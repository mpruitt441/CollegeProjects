#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE* input = stdin;
	//FILE* input = fopen("input.txt","r");
	FILE* output = stdout;
	//FILE* output = fopen("output.txt","w");
	char c;
	while ((c=getc(input)) != EOF)
	{
		if(!(isalpha(c)))
			continue;
		c=toupper(c);
		putc(c,output);
	}
}
