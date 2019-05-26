#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hex.h"
#include <assert.h>



/*The block cipher*/
char cipher(unsigned char block, char key)
{ //this is an affine cipher where "a" is fixed at 11 and b=key
    return (key+11*block)%256;
}

/*The inverse of the block cipher*/
char inv_cipher(unsigned char block, char key)
{ // 163 is the inverse of 11 mod 256
    return (163*(block-key+256))%256;
}

/*Code for galois multiplication borrowed from http://www.samiam.org/galois.html*/
unsigned char gmul(unsigned char a, unsigned char b) {
	unsigned char p = 0;
	unsigned char counter;
	unsigned char hi_bit_set;
	for(counter = 0; counter < 8; counter++) {
		if((b & 1) == 1)
			p ^= a;
		hi_bit_set = (a & 0x80);
		a <<= 1;
		if(hi_bit_set == 0x80)
			a ^= 0x1b;
		b >>= 1;
	}
	return p;
}


unsigned char simple_gcm(char* pt, char key, char iv, int len, char aad)
{
    /*Encrypts pt in CTR mode and returns a GCM MAC tag for the ciphertext*/
    /*Please use the gmul() function, above, for Galois multiplication*/
    /*Follow the diagram on page 135 of Understanding Cryptography to implement this function*/
    iv &= 0xF8;  //use only left 5 bits
    unsigned char g; //the GCM mac value
    int i =0, ctr=0;
    unsigned char H = cipher(0,key); 
    g = gmul(aad,H);
    unsigned char ek0 = cipher((unsigned char) (iv | ctr), key);
    ctr++;
    for(i=0; i < len;i++)
    {
        ctr &= 0x7; //use only right 3 bits 
        pt[i] ^= cipher((unsigned char) (iv | ctr), key);
        g ^=pt[i];
        g = gmul(H,g);
        ctr++;
    }

    g ^= ek0;
    return g;
}

#define VALID    1
#define INVALID    0

/*This function replaces each byte of ct with the decrypted plaintext.
  It returns VALID if the gcm tag of ct matches the parameter called "tag".
  It returns INVALID otherwise */
int gcm_decrypt_and_validate(char* ct, char key, char iv, int len, char aad, char tag)
{
    iv &= 0xF8;  //use only left 5 bits
    unsigned char g; //the GCM mac value
    int i =0, ctr=0;
    unsigned char H = cipher(0,key);
    g = gmul(aad,H);
    unsigned char ek0 = cipher((unsigned char) (iv | ctr), key);
    ctr++;
    for(i=0; i < len;i++)
    {
        ctr &= 0x7; //use only right 3 bits 
        ct[i] ^= cipher((unsigned char) (iv | ctr), key);
        g ^=ct[i];
        g = gmul(H,g);
        ctr++;
    }

    g ^= ek0;
    return VALID;
}

void print_ct(char* ct,int len)
{
    printf("ciphertext: 0x%s\n",bin2hex(ct,len));
}

/*Book errata: http://wiki.crypto.rub.de/Buch/en/download/Errata.pdf*/


/* Desired output:

~/Crypto_Spring_18/proj4$ gcc *.c
~/Crypto_Spring_18/proj4$ ./a.out
plaintext: vote
ciphertext: 0x3D391509
tag: 0x8D
validating tag:  valid
plaintext: outside
ciphertext: 0xC4C3B5BFBE8688
tag: 0xC4
validating tag:  valid
plaintext: plate
ciphertext: 0xFBFAC0D8D2
tag: 0x45
validating tag:  valid
plaintext: estate
ciphertext: 0xEEE5D5CDC3A7
tag: 0xAB
replacing tag with 0xAC
a.out: modes.c:160: main: Assertion `valid==VALID' failed.
validating tag: Aborted (core dumped)

*/

int main()
{
    char key = 8;
    char iv = 0xaa;
    int len;
    int a = 6;
    char ct[1000] = {0};
    char pt[12][100] = {"wife", "mother", "soldier", "risk", "endless", "hair", "vote", "outside", "plate", "estate", "slow", "baby"};
    char ct_ark[12][100] = {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
    char aad = 37;

    len = strlen(pt[a]);
    strncpy(ct,pt[a],len);
    printf("plaintext: %s\n",pt[a]);
    char tag = simple_gcm(ct,key,iv,len,aad);
    printf("ciphertext: 0x%s\n",bin2hex(ct,len));
    printf("tag: 0x%s\n",bin2hex(&tag,1));
    strncpy(ct_ark[a],ct,len);
    printf("validating tag: ");
    int valid = gcm_decrypt_and_validate(ct,key,iv,len,aad,tag);
    assert(valid==VALID);
    assert(strncmp(ct,pt[a],len)==0);
    printf(" valid\n");

    a++;
    iv = 0xc9;
    aad = 22;
    len = strlen(pt[a]);
    strncpy(ct,pt[a],len);
    printf("plaintext: %s\n",pt[a]);
    tag = simple_gcm(ct,key,iv,len,aad);
    printf("ciphertext: 0x%s\n",bin2hex(ct,len));
    printf("tag: 0x%s\n",bin2hex(&tag,1));
    strncpy(ct_ark[a],ct,len);
    printf("validating tag: ");
    valid = gcm_decrypt_and_validate(ct,key,iv,len,aad,tag);
    assert(valid==VALID);
    assert(strncmp(ct,pt[a],len)==0);
    printf(" valid\n");

    a++;
    iv = 0x69;
    aad = 200;
    len = strlen(pt[a]);
    strncpy(ct,pt[a],len);
    printf("plaintext: %s\n",pt[a]);
    tag = simple_gcm(ct,key,iv,len,aad);
    printf("ciphertext: 0x%s\n",bin2hex(ct,len));
    printf("tag: 0x%s\n",bin2hex(&tag,1));
    strncpy(ct_ark[a],ct,len);
    printf("validating tag: ");
    valid = gcm_decrypt_and_validate(ct,key,iv,len,aad,tag);
    assert(valid==VALID);
    assert(strncmp(ct,pt[a],len)==0);
    printf(" valid\n");

    a++;
    iv = 0x69;
    aad = 200;
    len = strlen(pt[a]);
    strncpy(ct,pt[a],len);
    printf("plaintext: %s\n",pt[a]);
    tag = simple_gcm(ct,key,iv,len,aad);
    printf("ciphertext: 0x%s\n",bin2hex(ct,len));
    printf("tag: 0x%s\n",bin2hex(&tag,1));
    strncpy(ct_ark[a],ct,len);
    tag++;
    printf("replacing tag with 0x%s\n",bin2hex(&tag,1));
    printf("validating tag: ");
    valid = gcm_decrypt_and_validate(ct,key,iv,len,aad,tag);
    assert(valid==VALID);
    assert(strncmp(ct,pt[a],len)==0);
    printf(" valid\n");
}