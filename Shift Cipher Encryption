#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE* input = stdin;
	FILE* output = stdout;
	char c,k='F';
	while ((c=getc(input)) != EOF)
	{
		c = (((c - 'A') + (k - 'A'))  %26) + 'A';
		putc(c,output);
	}
}

