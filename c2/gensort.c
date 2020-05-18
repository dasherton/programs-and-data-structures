#include <stdio.h>
#include <string.h>

void *maxelement(void *a, int n, int width, int(*fcmp)(const void *, const void *))
{
  int i;
  void *p=a, *pmax=a;

  for(i = 1; i < n; ++i)
  {
    p = (void *)((char *)p + width);
    if (fcmp(p, pmax) > 0) pmax = p;
  }
  return pmax;
}

typedef struct { int id; char name[30]; } person;

int personidcmp(const void *p1, const void *p2)
{
  return ((person *)p1)->id < ((person *)p2)->id ? -1 :
         ((person *)p1)->id > ((person *)p2)->id ? +1 : 0;
}

int personnamecmp(const void*p1, const void *p2)
{
  return strcmp(((person *)p1)->name, ((person *)p2)->name);
}

int main(int argc, char **argv)
{
  person *p_person, list[3] = {
    {5, "David"},
    {10, "George"},
    {2, "Kirsty"}
  };

  p_person = (person *)maxelement(list, sizeof(list)/sizeof(list[0]), sizeof(person), personidcmp);

  if (p_person)
  {
    printf("Person with largest id: %s id=%d\n",
      p_person->name, p_person->id);
  }

  p_person = (person *)maxelement(list, sizeof(list)/sizeof(list[0]), sizeof(person), personnamecmp);

  if (p_person)
  {
    printf("The person with the last alphabetically ordered name: %s id=%d\n",
      p_person->name, p_person->id);
  }

  return 0;
}