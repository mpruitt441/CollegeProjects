#include <stdio.h>
#include <ctype.h>

int main()

{
    char ciphertext[1000];
    int count = 0;
    char c;
    char key = 'x';

    while((c=getc(stdin))!= -1)
    {
        if (c=='\n')
        {
            puts("");
            continue;
        }
        c = tolower(c);
        int cnum = c-'a';
        int keynum = key-'a';
        int ciphernum = (cnum+keynum)%26;
        char cipherchar = ciphernum+'a';
        putc(cipherchar,stdout);
        ciphertext[count++]=cipherchar;
    }
    puts("");
    int i =0;
    for(i=0;i<count;i++){
        int ciphernum = ciphertext[i]-'a';
        int keynum = key-'a';
        int cnum = (ciphernum-keynum+26)%26;
        c = 'a'+cnum;
        putc(c,stdout);
    }

}