#include <stdio.h>

#include "intio.h"

int main()
{
  int i;

  if (readint(stdin, &i) == OK)
    printf("Your integer: %d\n", i);

  return 0;
}

