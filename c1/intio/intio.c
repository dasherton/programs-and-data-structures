#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#include "intio.h"

int readint(FILE *fp, int *n)
{
  int i, d, neg;
  char ch;

  /* Skip leading whitespace */
  do ch = getc(fp); while isspace(ch);
  if (ch == EOF) return EOF;

  neg = ch == '-';
  if (neg || ch == '+') ch = getc(fp);
  if (ch == EOF) return EOF;

  if (!isdigit(ch)) return INVALID; 
  i = ch - '0';
  if (neg) i = -i;

  while (ch = getc(fp), isdigit(ch))
  {
    d = ch - '0';
    if (neg) d = -d;
    
    if ((neg && i < (INT_MAX-d)/10) ||
        (!neg && i > (INT_MIN-d)/10))
      return OVFLOW;
  
    i = 10 * i + d;    
  }

  if (ch != EOF) ungetc(ch, stdin);
  *n = i;
  return OK;
}

int writeint(FILE *fp, int w, int x)
{
  puts("writeint()");
}

