/* chselsort.c: Straight selection, applied to an array of
				fixed-length character strings read in from
				a file and written to another file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 100

void chselsort(char **strings, int n)
{
	char *p, tmp[BUFLEN];
	int i, j;

	for (i = 0; i < n; ++i)
	{
		p = strings[i];

		for (j = i + 1; j < n - 1; ++j)
		{
			if (strcmp(strings[j], p) < 0)
			{
				p = strings[j];
			}

			/*
			 * Exchange the character sequence starting at p
			 * with that starting at strings[i]
			 */

			strcpy(tmp, p);
			strcpy(p, strings[i]);
			strcpy(strings[i], tmp);
		}
	}
}

void writeStrings(char **strings, int n, FILE *fp)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		fputs(strings[i], fp);
		fputc('\n', fp);
	}
}

int main(int argc, char **argv)
{
	char **strings, *input_filename, *output_filename, buf[BUFLEN + 1];
	int num_strings = 0, len, i;
	FILE *fpin, *fpout;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <input_filename> <output_filename>\n", argv[0]);
		return EXIT_FAILURE;
	}

	input_filename = argv[1];
	output_filename = argv[2];

	if ((fpin = fopen(input_filename, "r")) == NULL)
	{
		fprintf(stderr, "Cannot open %s\n", input_filename);
		return EXIT_FAILURE;		
	}

	/* Count number of strings for array memory allocation */
	while (fgets(buf, BUFLEN, fpin))
	{
		if (*buf != '\n')
		{
			++num_strings;
		}
	}
	rewind(fpin); /* Rewind the stream in order to use fpin again */

	strings = (char**)malloc(num_strings * sizeof(char*));
	if (strings == NULL)
	{
		perror("Memory allocation error");
		return EXIT_FAILURE;
	}

	while (fgets(buf, BUFLEN, fpin))
	{
		if (*buf == '\n')
		{
			continue;
		}

		len = strlen(buf);
		buf[len - 1] = '\0'; /* Overwrite LF */

		strings[i] = (char*)malloc(len);
		if (strings[i] == NULL)
		{
			perror("Memory allocation error");
			return EXIT_FAILURE;
		}

		strcpy(strings[i++], buf);
	}
	fclose(fpin);

	chselsort(strings, num_strings);

	if ((fpout = fopen(output_filename, "w")) == NULL)
	{
		fprintf(stderr, "Cannot open %s\n", output_filename);
		return EXIT_FAILURE;		
	}

	writeStrings(strings, num_strings, fpout);

	return EXIT_SUCCESS;
}
