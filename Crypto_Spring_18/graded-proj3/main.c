#include "des56.h"
#include "hex.h"
#include <stdlib.h>
#include <stdio.h>



#define DECRYPT 1
#define ENCRYPT 0

/*Compilation:
         To compile and run this code you will need to link with the other C files in this directory.
         The easiest solution is to use this compilation command:
         $ gcc *.c

         This will compile all C files in the directory and link the resulting object files to produce a single executable called "a.out".
         You can run a.out like this:
         $ ./a.out
*/




int main()
{
    unsigned char M1[8] = {'\x01','\x23','\x45','\x67','\x89','\xab','\xcd','\xef'};
    unsigned char M2[8] = {'\x41','\x23','\x45','\x67','\x89','\xab','\xcd','\xef'};
    unsigned char key[8]= {'h','a','m','b','u','r','g','r'};

    unsigned char set1[18];
    unsigned char set2[18];
    char* test1[17];
    
    FILE* file1;
    file1 = fopen("M1out.txt", "r");
    FILE* file2;
    file2 = fopen("M2out.txt", "r");

    
    
    printf("The key is (in hex):\n0x%s\n\n",bin2hex(key,8));
    keysched *ks = malloc(sizeof(keysched));
    fsetkey(key,ks);
    printf("Here are the values state by state for M1 and M2 \n\n\n");
    fencrypt(M1,ENCRYPT,ks);
    printf("\n\n\n");
    fencrypt(M2,ENCRYPT,ks);
    printf("\n\n\n");

    char* ciphertext=bin2hex(M1,8);
    printf("The ciphertext is (in hex):\n0x%s\n",ciphertext);
    
    
    char* m2cipher=bin2hex(M2,8);
    printf("The m2cipher is (in hex):\n0x%s\n\n\n",m2cipher);
    
    
    printf("The XOR difference between each state: \n");
    while((fgets(set1, 15, file1)) && (fgets(set2, 15, file2))) // truncate the newline character read in
    {

         for (int i = 0; i < 16; i++){
             printf("%d ", set1[i]^set2[i]);}

     printf("\nConverted to:\n");

         for (int i = 0; i < 16; i++){
             if (((set1[i]^set2[i])) >= 1 ){
                 if (((set1[i]^set2[i])%2) == 0)
                 {printf("%d", ((set1[i]^set2[i])%2) + 1);}// prints in binary. i was having a hard time converting the XOR to binary
                 else
                 {printf("%d", ((set1[i]^set2[i])%2));}
             }
             else if ((set1[i]^set2[i]) == 0){
             printf("%d", ((set1[i]^set2[i])%2));}
         }
    printf("\n\nNext: \n\n");

 // end while loop
    }


    fclose(file1);
    fclose(file2);

    /* the XOR between the cipher texts on each round
       damn thats hard
    My plan here is to do the following:
    1) Create a .txt file form the outputs = COMPLETE
    2) In des56 write all the hex to the file = COMPLETE
    3) Then XOR the hex in the main file = Changed to XOR to Binary (Having a hard time doing hex)
    4) Output the XOR = Unsure if correct
   */
    


}





















