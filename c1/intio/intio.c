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

#define CHARBUFSIZE 50
#define putchr(ch) if (putc(ch, fp) == EOF) return EOF;

int writeint(FILE *fp, int w, int x)
{
  int n = 0, i, r, neg = x < 0;
  char digs[CHARBUFSIZE];

  if (x==0) { digs[0] = '0'; n = 1; } else
  do
  {
    r = x % 10;
    digs[n++] = '0' + (neg ? -r : r);
    if (n==CHARBUFSIZE) return OVFLOW; /* Unlikely ot occur */
    x /= 10;
  } while (x);
  i = w - n;
  if (neg) --i;
  while(i-- > 0) putchr(' ');
  if (neg) putchr('-');
  for(i = n-1; i >= 0 ; --i) putchr(digs[i]);

  return OK;
}

