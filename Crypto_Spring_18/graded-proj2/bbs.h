#ifndef BLUMBLUMSHUB
#define BLUMBLUMSHUB

using namespace std;

#include <gmpxx.h>
#include <string.h>

#define SEED_SIZE    32

class key
{
    public:
    mpz_class M,p,q,x;
};

class bbs
{
    //private:
    public:
    int num_bits;
    char seed[SEED_SIZE];
    mpz_class get_prime();
    key k;
    mpz_class x;
    void key_gen();
    string get_entropy(int num_bytes);
    void get_seed_x();

    void next_state();
    void test();
    unsigned char encrypt_byte(unsigned char c);
    void encrypt_buffer(char* s,int len, mpz_class x_0);

    public:
    bbs(int num_security_bits=512);
    unsigned char get_stream_byte();
};

#endif