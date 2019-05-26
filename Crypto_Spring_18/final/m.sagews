︠b88a134d-bcf1-4c26-8fc5-1ff53877a784i︠
%md

## 1

Which block cipher modes allow you to decrypt a single block of ciphertext without decrypting the entire ciphertext?
︡788fb699-4b54-4df6-9f29-f69cf0b4e4e7︡{"done":true,"md":"\n## 1\n\nWhich block cipher modes allow you to decrypt a single block of ciphertext without decrypting the entire ciphertext?"}
︠b6c6162d-fc84-4e29-8bb8-d48a3f928789︠
%md

ECB allows you to decrypt a single block of ciphertext without decrypting the entire ciphertext because each encryption is independent of each other.
CTR aso allows you to decrypt a single block of ciphertext without decrypthing everything because if you know the counter of the plaintext you are decrypting, you can decrypt each ciphertext.

︡c6cbc6f8-ac45-4fe2-8de2-afa8e0eca954︡
︠27035fce-7ea0-4ea1-94c8-84069e04d1f4︠
︡5c94297f-908e-4f84-96ec-7b4cbe22cb82︡{"done":true}︡
︠d6aac760-bfd3-462e-b536-0b25efa07828i︠
%md

## 2

From the modes in your answer to number 1:  Which modes allow you to decrypt a single block of ciphertext, alter it, and then encrypt it again all without having to decrypt the entire document?
︡733865f8-f2ab-4832-a135-a8d8ab56bfcf︡{"done":true,"md":"\n## 2\n\nFrom the modes in your answer to number 1:  Which modes allow you to decrypt a single block of ciphertext, alter it, and then encrypt it again all without having to decrypt the entire document?"}
︠5a133df7-d805-41ee-8b2c-db7300649e4f︠
%md

ECB easily allows you to decrypt a single block of ciphertext, alter it, and then encrypt again.
You could also do this with CTR, but you would need to know the counter.
︡b51716e6-a6f6-40bd-976e-b2c796e172ff︡
︠1e8175f3-38d8-4824-82ff-e4ab161b94b5︠
︡f0d7cfb6-ef0f-48ed-a219-50887f618eb3︡{"done":true}︡
︠bcbc44a2-ad89-4583-babc-7587bb2eee36s︠
## The following code is for number 3
## In number 3 we will hash a document and then sign the hash using the RSA signature algorithm

set_random_seed(100)
## We are going to hash and sign the following text document using RSA
document = "Blah blah blah blah toast toast toast."
import hashlib
doc_hash_as_string = hashlib.sha256(document).hexdigest()
doc_hash_as_int = int(doc_hash_as_string,16)
thing_to_sign = doc_hash_as_int

## We will use RSA.  We need to generate some parameters.
p = random_prime(2**128)  #a random prime less than 2**128
q = random_prime(2**128)
N = p*q
phi_N = (p-1)*(q-1)
e = 7
assert gcd(e,phi_N)==1
d = inverse_mod(e,phi_N)
assert (d*e)%phi_N == 1
signed = (thing_to_sign ** e) % N

print "N=",N
print "e=",e
print "d=",d
print "Thing to sign = ",thing_to_sign
print "Signed = ", signed

︡db13cef2-406d-4f05-9b0f-2efa09592e52︡{"stdout":"N= 11783958142897916431882301185888352387993287628820763207160455146708227855773\n"}︡{"stdout":"e= 7\n"}︡{"stdout":"d= 3366845183685118980537800338825243539333764870635049259135683154378007034871\n"}︡{"stdout":"Thing to sign =  105627108855101827529740540144339953915874516805280786479090741954050376924960\n"}︡{"stdout":"Signed =  9183129296974453436417185433393836266482395940630198159794259598050971214580\n"}︡{"done":true}︡
︠3a7e7bc8-bb02-44b0-a0ca-282597baff00i︠
%md

## 3

What is the signature produced by signing `thing_to_sign` with the RSA parameters generated in the above code?
︡42d8618d-fd57-47b9-bd19-a903fdd187ae︡{"done":true,"md":"\n## 3\n\nWhat is the signature produced by signing `thing_to_sign` with the RSA parameters generated in the above code?"}
︠6c131d4d-50de-4b54-a8ba-281597154348︠
9183129296974453436417185433393836266482395940630198159794259598050971214580

︡e95d2058-e831-4096-b4f3-7bdb39bb592e︡
︠024ec23b-6209-453b-a901-58d6b6b05234s︠

"""
The following code is for number 4.
Please run each cell.
"""
import Crypto
from Crypto.PublicKey import RSA
key = RSA.generate(1024)
nonce = 24
ciphertext = key.encrypt("message",nonce)

︡6a071227-bb40-495c-97af-bb3eb4a261a9︡{"stdout":"'\\nThe following code is for number 4.\\nPlease run each cell.\\n'\n"}︡{"stderr":"/ext/sage/sage-8.1/local/lib/python2.7/site-packages/Crypto/Util/number.py:57: PowmInsecureWarning: Not using mpz_powm_sec.  You should rebuild using libgmp >= 5 to avoid timing attack vulnerability.\n  _warn(\"Not using mpz_powm_sec.  You should rebuild using libgmp >= 5 to avoid timing attack vulnerability.\", PowmInsecureWarning)\n"}︡{"done":true}︡
︠04e1fe88-558f-4738-903e-b1afa0be331ds︠
%timeit

ciphertext = key.encrypt("message",nonce)

︡350002b7-4a0e-479f-bb02-8c41a0db4f5f︡{"stdout":"625 loops, best of 3: 30.8 µs per loop"}︡{"stdout":"\n"}︡{"done":true}︡
︠9b366b91-bc32-4301-8a91-e8fc17bb5e9fs︠

%timeit

key.decrypt(ciphertext)
︡c294164a-8a2f-4dbd-aec6-15c751931bf9︡{"stdout":"625 loops, best of 3: 478 µs per loop"}︡{"stdout":"\n"}︡{"done":true}︡
︠26a38199-a15e-472a-99d4-0f856e061a05i︠
%md

## 4

From the above output you can see that RSA decryption is at least 10 times slower than RSA encryption.  Why is that?
︡973eeb67-def1-476e-95c4-77b7692f9df6︡{"done":true,"md":"\n## 4\n\nFrom the above output you can see that RSA decryption is at least 10 times slower than RSA encryption.  Why is that?"}
︠9a6685f8-8e60-48ff-a8fd-42dc56f19e50︠
%md

This is because RSA decryption relies on computing extremely large numbers, while RSA encryption doesn't.
It is relatively easy to encrypt with RSA, but there is 'onewayness' when decrypting due to the difficulty of integer factorization.
︡50fe1ae1-1272-4df9-9ea4-241eff8ed733︡
︠97f03bca-461a-4a41-ab59-de8df2d2943ds︠
︡5f63cf04-db70-4c83-90c6-677b769b1a09︡{"done":true}︡
︠2afdb527-41b5-4ae6-8183-5f6064a5de06i︠
%md

## 5

We have said in class that $\phi(N)$ is part of the private key in RSA.  In this problem we show that if $\phi(N)$ is known, then $p$ and $q$ can be recovered, where $N=pq$.

First we explain in outline how the process works.  Recall that $N$ is public information, so it is always known.  If $\phi(N)$ is also known then the attacker has the following system of two equations in two unknowns $x$ and $y$:

$$
\begin{align}
    N &= xy \\
    \phi(N) &= (x-1)(y-1)
\end{align}
$$

The code for solving a system of equations like this in Sage is the following.

```
var('x,y')
eqn = N==x*y
eqn2 = phi_N == (x-1)*(y-1)
eqn2.substitute(x=N/y).solve(y)
```

<br>
In the code box below we define $N$ and $\phi(N)$ in an instance of RSA.  What are $p$ and $q$?
︡73e1f4b5-4481-49b0-9fb6-fa12c8ebf5a5︡{"done":true,"md":"\n## 5\n\nWe have said in class that $\\phi(N)$ is part of the private key in RSA.  In this problem we show that if $\\phi(N)$ is known, then $p$ and $q$ can be recovered, where $N=pq$.  \n\nFirst we explain in outline how the process works.  Recall that $N$ is public information, so it is always known.  If $\\phi(N)$ is also known then the attacker has the following system of two equations in two unknowns $x$ and $y$:\n\n$$\n\\begin{align}\n    N &= xy \\\\\n    \\phi(N) &= (x-1)(y-1)\n\\end{align}\n$$\n\nThe code for solving a system of equations like this in Sage is the following.\n\n```\nvar('x,y')\neqn = N==x*y\neqn2 = phi_N == (x-1)*(y-1)\neqn2.substitute(x=N/y).solve(y)\n```\n\n<br>\nIn the code box below we define $N$ and $\\phi(N)$ in an instance of RSA.  What are $p$ and $q$?"}
︠9a7eb03d-36f2-40c0-b74b-5630a8b232ab︠
phi_N = 7757037190426784864779683665507864461065793214098073809007844403725205113779210544415486912649460325547582520790441874187113756211915777180137638519685884977274896922761855753101668343751872356865997931193789503257079403576920104920170766361794640887565536839865017206146205908653144522993641289103255966661426752585338858469654113461908764465970509728511946825146743511988274129549274410771843712266791707374844930600880292925891121237287490656362299293100604154192371388006306366798917082496335540653065270399314705889801607303698432662544110188573966184895928638161069821862707939515965317018297669085607866939896
N = 7757037190426784864779683665507864461065793214098073809007844403725205113779210544415486912649460325547582520790441874187113756211915777180137638519685884977274896922761855753101668343751872356865997931193789503257079403576920104920170766361794640887565536839865017206146205908653144522993641289103255966661629177003746984394280831190658231538450211675132561706287454735644278172881751126136181103769020081713021204793910775770662417367466730462388107919551464356898205035289281546407048722558725244947840852483523006508182233160680624475979252083891295967974903970217524889549255968246242132945989558074066058936727

var('x,y')
eqn = N==x*y
eqn2 = phi_N == (x-1)*(y-1)
eqn2.substitute(x=N/y).solve(y)
p == 151080777476475020388610606955325559129871604038573108929051010282281282511632795733159064928431563763984593227932746129069107896389567565204499259028123483644568503701138396529229201519773737550093751769622239616636846358195230492473685290496733620027909424588234052149355900490816320951345748694369205056739
q == 51343640931650904238107121794141513349830342582041772211660213373722760820843919631178326573796810574191680965097736715702188233789672240821309367422736719061265143581836783078902438542615966744681830314586061001743779498786961320961456604820596163051065907468221015537192128239460494976346140294088986940093
︡2676979c-d22f-4c63-8d58-468d5ec3141d︡{"stdout":"(x, y)\n"}︡{"stdout":"[y == 151080777476475020388610606955325559129871604038573108929051010282281282511632795733159064928431563763984593227932746129069107896389567565204499259028123483644568503701138396529229201519773737550093751769622239616636846358195230492473685290496733620027909424588234052149355900490816320951345748694369205056739, y == 51343640931650904238107121794141513349830342582041772211660213373722760820843919631178326573796810574191680965097736715702188233789672240821309367422736719061265143581836783078902438542615966744681830314586061001743779498786961320961456604820596163051065907468221015537192128239460494976346140294088986940093]"}︡{"stdout":"\n"}︡{"done":true}︡
︠b47b4172-7057-4d5c-b69c-cf1fde6ca683s︠
︡90d858af-4ac6-444e-9288-63d294191806︡{"done":true}︡
︠7b4e63f2-518e-4627-80d4-97b653438da2i︠
%md

## 6

Suppose you have a playlist with 1000 songs and you set it to play on random.  This means that a song will be selected uniformly at random, and when that song completes, another song will be randomly selected and played, etc. By a _collision_ we mean the same song plays twice.

1.  Give an expression for the probability that there are no collisions after 5 songs have played.
1.  About how many songs will be played before the chance of some collision exceeds 50 percent?
︡ff6a485e-ba2c-4a7c-ab7e-41c60b4f0e97︡{"done":true,"md":"\n## 6\n\nSuppose you have a playlist with 1000 songs and you set it to play on random.  This means that a song will be selected uniformly at random, and when that song completes, another song will be randomly selected and played, etc. By a _collision_ we mean the same song plays twice.  \n\n1.  Give an expression for the probability that there are no collisions after 5 songs have played.\n1.  About how many songs will be played before the chance of some collision exceeds 50 percent?"}
︠5d9ec93b-f0b9-4009-b5e5-e095456a0be3︠
%md

Using the "choose" from probability to calculate without collisions:
1. (1000!)/(1000 - 5)!* (5!)
2. 500 songs will be played before the chance of some collision exceeds 50%.
Math:
No collision at first song (0/1000)
.... at 50 songs 50/1000
.... at 500 songs 500/1000
︡bc1c1cf3-7219-494f-b838-a1ac9d046d4a︡
︠62d96540-a447-4374-9f06-e00bba489b55s︠
︡4a5abd85-5f84-4f1b-bf90-114ee26dd935︡{"done":true}︡
︠e07a6c36-69cc-43da-92e9-3310c4fb9813i︠
%md

## 7

Below is some code that could be used to do Diffie Hellman key exchange.  What are:

1.  Bob's public key
2.  The shared secret
︡26d766f1-d866-4681-845b-6e5c5573ab76︡{"done":true,"md":"\n## 7\n\nBelow is some code that could be used to do Diffie Hellman key exchange.  What are:\n\n1.  Bob's public key\n2.  The shared secret"}
︠4de3bd06-5c6c-450f-81f9-8b43da5d9220︠

#Diffie Hellman key exchange
set_random_seed(20)
q = random_prime(2**200)
g = Zmod(q).multiplicative_generator()
g = ZZ(g) #back to integer type
Alice_private_key = randint(2,q-1)
Alice_public_key = pow(g,Alice_private_key,q)
Bob_private_key = randint(2,q-1)
Bob_public_key = pow(g,Bob_private_key,q)
alicesecret = pow(Bob_public_key,Alice_private_key,)
bobsecret =  pow(Alice_public_key,Bob_private_key, q)

print Bob_private_key
print Bob_public_key
bobsecret == alicesecret
print "The shared secret is ", bobsecret

Sage was taking very long on this sheet to do anything so I created a separate sheet and calculated it there.
1. 1296973488537025976206377650482441286232171243283807551898335
2. 1114843307672854130823153934546641163632309419764450970048486
︡f58f236f-8321-4aad-ab3b-db1123d0d7c8︡
︠fdd60200-0802-4cfa-9fff-b2936320119di︠
%md

## 8

Suppose you know the following information about a session of DHKE

```
large prime q =  423252520953198337840033317224858054609853452753583409763851
multplicative generator g =  2
shared secret s =  296587865297973287605557567271788185251169775531243838428609
Bob's private key =  58478780571249529133241976781763939939088012084031023430614
```
<br>
What is Alice's private key?
︡5bd15627-7523-4385-834e-cbbd102e75d0︡{"done":true,"md":"\n## 8\n\nSuppose you know the following information about a session of DHKE\n\n```\nlarge prime q =  423252520953198337840033317224858054609853452753583409763851\nmultplicative generator g =  2\nshared secret s =  296587865297973287605557567271788185251169775531243838428609\nBob's private key =  58478780571249529133241976781763939939088012084031023430614\n```\n<br>\nWhat is Alice's private key?"}
︠b006d566-c18f-4f32-99f1-ceb8e4d48680︠

This is infeasible to compute


︡1d8759f9-18d2-4471-ac27-7e6cfaa1f4b8︡
︠a1695a3e-11f4-40d8-b9fb-55fd56d7aa45s︠
︡0d06a36f-6e4a-4348-8a69-10d008335249︡{"done":true}︡
︠046afda3-55d1-44b7-885a-509ecaeebebai︠
%md

## 9

What are the properties that a cryptographically secure hash function should have?
︡67cd5b1a-879d-489c-a939-73bdfa51fea9︡{"done":true,"md":"\n## 9\n\nWhat are the properties that a cryptographically secure hash function should have?"}
︠cbb516c5-7311-490f-a31a-bf435c6fbebe︠
%md

1. Can take arbitrarily long inputs
2. Fixed length digest
3. Efficient
4. Preimage resistance (can't go from hash to file)
5. 2nd preimage resistance
6. Collision resistance (can't find 2 docs with same hash)

︡a18250b7-82bf-4395-889a-f04df905f5af︡
︠0dbd0606-eeb7-463d-925a-d1bdb34c0a44s︠
︡25be4caf-852f-4fb9-b8c7-66379ab2e5e1︡{"done":true}︡
︠2ae40f1f-6b40-40b7-85c5-e965ad418767i︠
%md

## 10

What is the difference between a hash function that might be used for a hash table data structure and a cryptographically secure hash function?
︡aaeb2576-f715-4537-b67a-c2a3d4ca9b7c︡{"done":true,"md":"\n## 10\n\nWhat is the difference between a hash function that might be used for a hash table data structure and a cryptographically secure hash function?"}
︠1b7cfe12-d5b9-467a-b7a2-8eab8c963e3c︠
%md

A non cryptographically secure hash function avoids collisions for non-malicious input.

Cryptographically secure hash functions try to ensure the above and these properties:
1. Can take arbitrarily long inputs
2. Fixed length digest
3. Efficient
4. Preimage resistance (can't go from hash to file)
5. 2nd preimage resistance
6. Collision resistance (can't find 2 docs with same hash)









