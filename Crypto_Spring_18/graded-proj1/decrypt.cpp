#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void check(int argc, char* argv[])
{
	if (argc != 2)
	{
		puts("usage: $ ./decrypt keychar");
		exit(1);
	}
	if (! isalpha(argv[1][0]))
	{
		puts("key character must be alphabetical");
		exit(1);
	}
	if (argv[1][0] != toupper(argv[1][0]))
	{
		puts("key character must be upper case");
		exit(1);
	}
}

int main(int argc,char* argv[])
{
	check(argc,argv);
	char k = argv[1][0];
	printf("key = %c\n",k);
	FILE* input = stdin;
	FILE* output = stdout;
	char c;
	while ((c=getc(input)) != EOF)
	{
        c = ((((c - 'A') - (k - 'A'))+26)  %26) + 'A';
		putc(c,output);
	}
}
