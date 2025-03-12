#include <stdio.h>
#include <stdlib.h>
#include <graphviz/gvc.h>

/* TODO: Renamed due to conflict with graphviz */
typedef struct MyEdge {
    int vertex_index;
    struct MyEdge* next;
} myedge_t;

typedef struct {
    int count; /* Number of predecessors,
                  OR, a "pointer" to the next Vertex in the "no-predecessor" stack
                  OR, ABSENT if end of the "no-predecessor" stack */
    myedge_t* edges; /* Linked-list of Edges to successor vertices */
} vertex_t;

/* Ends stack of vertices with no predecessors */
#define END_OF_STACK (-1)
/* Vertex is not mentioned in our input file */
#define ABSENT (-2)

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];

    /* Open vertices file */
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Cannot open: %s", argv[1]);
        return EXIT_FAILURE;
    }
    /* Parse graph */
    Agraph_t* graph = agread(fp, NULL);
    if (graph == NULL)
    {
        fprintf(stderr, "Graph read failed\n");
        return EXIT_FAILURE;
    }
    fclose(fp);

    if (!agisdirected(graph))
    {
        fprintf(stderr, "Graph is not directed\n");
        return EXIT_FAILURE;
    }

    int I, J; /* Uppercase namings denote user-named vertices */
    int local_min, local_max;
    int global_min, global_max;
    int is_first = 1;
    for (Agnode_t *node = agfstnode(graph); node; node = agnxtnode(graph, node))
    {
        for (Agedge_t *edge = agfstout(graph, node); edge; edge = agnxtout(graph, edge))
        {
            I = strtol(agnameof(agtail(edge)), NULL, 10);
            J = strtol(agnameof(aghead(edge)), NULL, 10);

            printf("i=%d, j=%d\n", I, J);

            if (I < J)
            {
                local_min = I;
                local_max = J;
            }
            else
            {
                local_min = J;
                local_max = I;
            }

            if (is_first)
            {
                global_min = local_min;
                global_max = local_max;
                is_first = 0;
            }
            else
            {
                if (local_min < global_min)
                {
                    global_min = local_min;
                }
                if (local_max > global_max)
                {
                    global_max = local_max;
                }
            }
        }
    }

    /* This region includes any "missing" vertices in between the ones provided */
    int num_vertices = global_max - global_min + 1;

    /* Allocate topological order array */
    int *topological;
    topological = (int*)malloc(num_vertices * sizeof(int));
    if (topological == NULL)
    {
        fprintf(stderr, "Topological memory allocation failed\n");
        return EXIT_FAILURE;
    }

    /* Allocate vertices */
    vertex_t *vertices = (vertex_t*)malloc(num_vertices * sizeof(vertex_t));
    if (vertices == NULL)
    {
        fprintf(stderr, "Vertices memory allocation failed\n");
        return EXIT_FAILURE;
    }
    for(int i = 0; i < num_vertices; i++)
    {
        vertices[i].count = ABSENT;
        vertices[i].edges = NULL;
    }

    /* Build adjacency list */
    int i, j;
    for (Agnode_t *node = agfstnode(graph); node; node = agnxtnode(graph, node))
    {
        for (Agedge_t *edge = agfstout(graph, node); edge; edge = agnxtout(graph, edge))
        {
            /* Convert into integers */
            I = strtol(agnameof(agtail(edge)), NULL, 10);
            J = strtol(agnameof(aghead(edge)), NULL, 10);

            /* Convert user-named vertices to array indices */
            i = I - global_min;
            j = J - global_min;

            /* Mark vertices as "present" */
            if (vertices[i].count == ABSENT)
            {
                vertices[i].count = 0;
            }
            if (vertices[j].count == ABSENT)
            {
                vertices[j].count = 0;
            }

            myedge_t *edge = (myedge_t*)malloc(sizeof(myedge_t));
            if (edge == NULL)
            {
                fprintf(stderr, "Edge memory allocation failed: %d -> %d\n", I, J);
                return EXIT_FAILURE;
            }
            edge->vertex_index = j;
            /* Insert edge at the head of the linked-list */
            edge->next = vertices[i].edges;
            vertices[i].edges = edge;
            /* Increase destination vertex's predecessor count */
            vertices[j].count++;
        }
    }
    agclose(graph);

    /* Form linked-stack of vertices with no predecessor */
    int stack_head = END_OF_STACK;
    for (int i = 0; i < num_vertices; i++)
    {
        if (vertices[i].count == 0)
        {
            /* Insert vertex at head of the stack */
            vertices[i].count = stack_head;
            stack_head = i;
        }
    }

    /* Print vertices in topological order */
    int topol_idx = 0;
    int idx;
    myedge_t *edge;
    for(int i = 0; i < num_vertices; ++i)
    {
        /* Skip any absent vertices */
        while (vertices[i].count == ABSENT)
        {
            ++i;
        }

        /* If the stack is empty, then a cycle was detected */
        if (stack_head == END_OF_STACK)
        {
            fprintf(stderr, "Cycle detected\n");
            return EXIT_FAILURE;
        }

        /* Pop a vertex off the head of the stack */
        j = stack_head;
        stack_head = vertices[j].count;

        /* Store the vertex */
        J = j + global_min;
        topological[topol_idx++] = J;

        /* Decrement the count of each successor */
        while ((edge = vertices[j].edges) != NULL)
        {
            idx = edge->vertex_index;
            vertices[idx].count--;
            /* If the successor has no more predecessors ... */
            if (vertices[idx].count == 0)
            {
                /* ... push it to the head of the stack */
                vertices[idx].count = stack_head;
                stack_head = idx;
            }
            vertices[j].edges = edge->next;
        }
    }

    /* Print topological order */
    printf("Topological order: ");
    for(int i = 0; i < num_vertices; i++)
    {
        printf("%d ", topological[i]);
    }

    /* Free memory */
    free(topological);
    myedge_t* next;
    for(int i = 0; i < num_vertices; i++)
    {
        edge = vertices[i].edges;
        while (edge != NULL)
        {
            next = edge->next;
            free(edge);
            edge = next;
        }
    }
    free(vertices);

    return EXIT_SUCCESS;
}
