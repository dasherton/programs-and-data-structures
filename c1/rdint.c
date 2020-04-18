/* rdint.c: Reads an integer from stdin (preliminary version) */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int rdint(void)
{
  int i, d, neg;
  char ch;

  /* Skip any leading whitespace */
  do ch = getchar(); while (isspace(ch));

  /* Is the integer going to be negative? */
  neg = ch == '-';

  /* Ignore possible signed/unsigned signifier */
  if (neg || ch == '+') ch = getchar();

  /* First character must be a digit */
  if (!isdigit(ch)) puts("Invalid number"), exit(1);

  /* Convert first character to integer */
  i = ch - '0';

  /* Apply Horner's rule to subsequent digits */
  while (ch = getchar(), isdigit(ch))
  {
    d = ch - '0';
    i = 10 * i + d;
  }

  /* Replace last non-digit char to stdin */
  ungetc(ch, stdin);

  return neg ? -i : i;
}

int main()
{
  printf("Enter integer: ");
  int i = rdint();
  printf("Your integer: %d\n", i);
  return 0;
}

