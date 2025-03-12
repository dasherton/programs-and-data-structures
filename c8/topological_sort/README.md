# Topological Sort

Reads a Graphviz digraph and prints the topological order.


# Graphviz
This program relies on the Graphviz library and assumes you have iti nstalled on your machine.
```
# Install
$ sudo apt-get install libgraphviz-dev

# Version
$ dot -V
dot - graphviz version 2.43.0 (0)

# Visualize
$ dot graph.txt -Tpng > graph.png
```

## Dev
For quick development I have made use of `entr` to run dot, compile the code and run it with any relevant source code changes.

```
ls main.c rsc/*.dot makefile | entr -r sh -c 'make clean && make && dot rsc/dag.dot -Tpng > rsc/dag.png && ./topol rsc/dag.dot'
```
