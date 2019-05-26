#### Project 4

This project concerns implementing a simple variant of Galois Counter Mode (GCM).  Please see the textbook *Understanding Cryptography*, p. 134.  Take note of the textbook errata:

http://wiki.crypto.rub.de/Buch/en/download/Errata.pdf

Fix the missing parts of the code so that the output of `modes.c` is the following:


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
