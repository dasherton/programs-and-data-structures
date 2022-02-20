/* rec2.c: A second example of recursion */

#include <stdio.h>

void p(int n)
{
	if (n > 0)
	{
		p(n - 40);
		printf("%3d", n);
		p(n - 20);
	}
}

int main()
{
	p(80);
	puts("");
	return 0;
}
