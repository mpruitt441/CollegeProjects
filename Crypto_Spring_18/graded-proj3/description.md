## Project 3
### DES
#### CSCI 360
#### Due: 3/20/18

---

The goal in this project is to find the "round by round" differences between two nearly identical plaintexts.  The two plaintexts we will use are:

    unsigned char M1[8] = {'\x01','\x23','\x45','\x67','\x89','\xab','\xcd','\xef'};
    unsigned char M2[8] = {'\x41','\x23','\x45','\x67','\x89','\xab','\xcd','\xef'};

And the key for both plaintexts is this:

    unsigned char K[8]= {0x13,0x34,0x57,0x79,0x9B,0xBC,0xDF,0xF1};


The desired output is $$(L_i^{M_1}R_i^{M_1}) \oplus (L_i^{M_2}R_i^{M_2})$$ where

1. $i = 0,1,2,\ldots,15$
2. $\oplus$ denotes exclusive OR
3. $L_i^{M_1}$ is the left hand state in the $i$th round for the plaintext M1, and $R_i^{M_1}$ is the right hand state in the $i$th round for the plaintext M1.
4. $L_i^{M_2}$ is the left hand state in the $i$th round for the plaintext M2, and $R_i^{M_2}$ is the right hand state in the $i$th round for the plaintext M2.


In other words for each round we need to find the XOR of the states for that round for the respective plaintexts.

More details can be found in this video:

https://youtu.be/IDFwMGwgyRU



