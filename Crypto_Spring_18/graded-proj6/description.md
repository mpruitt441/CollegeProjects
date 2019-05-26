## Project 6
#### Discrete log cracking
##### Due: last day of class

In this project you will break the discrete log problem in order to crack the Elgamal cipher.  This cipher is a little (a lot) different from the signature algorithm named after Elgamal.

Please read the Wikipedia article (we use the same notation in this project): [https://en.wikipedia.org/wiki/ElGamal_encryption](https://en.wikipedia.org/wiki/ElGamal_encryption)

The basic idea is to use a Diffie-Hellman style shared secret to encrypt information.

In this folder you will see a file called `p6.sagews`.  This file contains a simple implementation of Elgamal in Sage/Python.  Using this code I have generated some worked examples of using Elgamal encryption (please see Examples section below).  You can use these examples to test your code.

After the Examples section you will find a section called Open Problems.  Your job is to find the solution to these problems using code that you write in either C,C++, or Sage/Python.

The problems come in three difficulty levels: Easy (20 bits), Hard (44 bits), and Very hard (100 bits).

_The temptation to plagiarize code for this assignment will be especially acute.  It will **not** be in your interest to submit plagiarized code._

For the Easy problem you can just write a brute force attack in C++ using ordinary data types.  **You must write your own code to get credit for this problem**.  If you want you can borrow code that does xgcd or fast modular exponentiation, but that's all.  You can use the GMP library if desired, but not a discrete log solver.

For the 44 bit problem the brute force search for the private key value $x$ (or $s^{-1}$) will not run in a reasonable amount of time.  For this problem I suggest you implement Shank's Baby Step Giant Step algorithm as described in the book.  You can still use ordinary datatypes but you'll need to make sure your integers are 64 bit, for instance by using the [`uint64_t`](https://www.badprog.com/c-type-what-are-uint8-t-uint16-t-uint32-t-and-uint64-t) type.  You must write your own code to get credit for this problem.  If you want you can borrow code that does xgcd or fast modular exponentiation, but that's all.  You can use the GMP libraries, but not a discrete log solver.

For the 100 bit problem, unlike the other two problems, you do not need to write your own code.  You can use library calls or other software packages.  Sage has a built-in discrete log function which may work to solve this problem: [http://doc.sagemath.org/html/en/constructions/number_theory.html](http://doc.sagemath.org/html/en/constructions/number_theory.html).

If that doesn't work you may need to Google around for something fancier that can do index calculus.

A note on sanity:  Most people will not be able to implement Shank's algorithm.  Please don't have a nervous breakdown if you can't get it -- do that one last.  Relax and have fun :)  You will still get a high score just by submitting answers to the Easy and Very hard questions.  Note that the answer I want to see is _how you got the solution_ not some number that happens to work.

---

### Examples

Easy (20 bits) example 1:

```
A problem...
The public key: {'q': 348643, 'h': 294562, 'g': 2, 'G': Ring of integers modulo 348643}
The ciphertext: (151381, 92584)
What's the message?
(solution: 244352)
```

Easy (20 bits) example 2:

```
A problem...
The public key: {'q': 785483, 'h': 374425, 'g': 2, 'G': Ring of integers modulo 785483}
The ciphertext: (372525, 494556)
What's the message?
(solution: 16612)
```

Hard (44 bits) example 1:

```
A problem...
The public key: {'q': 15937348385107, 'h': 13189720630075, 'g': 7, 'G': Ring of integers modulo 15937348385107}
The ciphertext: (9694725618595, 4706696182598)
What's the message?
(solution: 81288)
```

Hard (44 bits) example 2:

```
A problem...
The public key: {'q': 15640518517999, 'h': 378048791352, 'g': 3, 'G': Ring of integers modulo 15640518517999}
The ciphertext: (10892901456668, 388064800091)
What's the message?
(solution: 269430)
```

Very hard (100 bits) example 1:

```
A problem...
The public key: {'q': 962643117310303072860592859513, 'h': 344013249000144636969699266218, 'g': 3, 'G': Ring of integers modulo 962643117310303072860592859513}
The ciphertext: (720208476315726349963005038336, 392887901381657116308431863196)
What's the message?
(solution: 33572)
```
Very hard (100 bits) example 2:

```
A problem...
The public key: {'q': 962643117310303072860592859513, 'h': 344013249000144636969699266218, 'g': 3, 'G': Ring of integers modulo 962643117310303072860592859513}
The ciphertext: (720208476315726349963005038336, 957253416311318124662176577336)
What's the message?
(solution: 232795955077325143502737554221)
```

## Open problems (you solve!)

The easy (20 bit) problem:

```
A problem...
The public key: {'q': 495433, 'h': 482693, 'g': 5, 'G': Ring of integers modulo 495433}
The ciphertext: (41828, 330193)
What's the message?
```

The hard (40 bit) problem:

```
A problem...
The public key: {'q': 1010734765291, 'h': 219307542473, 'g': 3, 'G': Ring of integers modulo 1010734765291}
The ciphertext: (983698100705, 780893957254)
What's the message?
```

The very hard (100 bit) problem:

```
A problem...
The public key: {'q': 882500089417806583096361924911, 'h': 844902002641556211595826411889, 'g': 15, 'G': Ring of integers modulo 882500089417806583096361924911}
The ciphertext: (11273804902657113756458670808, 590787801714342290779861161563)
What's the message?
```
