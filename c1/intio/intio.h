/*
 * intio.h: A header file to be used in connection with the functions
 * readint() and writeint()
 */

#define OK 1       /* Success*/
#define INVALID 1  /* Invalid character read */ 
#define OVFLOW 2   /* Integer overflow */

int readint(FILE *fp, int *n);
int writeint(FILE *fp, int w, int x);

