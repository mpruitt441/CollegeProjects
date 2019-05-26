︠9a5a15dc-8374-4fed-ac8a-128c73cfce18i︠
%md

[Elgamal cipher](https://en.wikipedia.org/wiki/ElGamal_encryption).

Keygen:
︡a3d923cd-9c64-4b0b-b1d1-b9d76653321d︡{"done":true,"md":"\n[Elgamal cipher](https://en.wikipedia.org/wiki/ElGamal_encryption).\n\nKeygen:"}
︠3cc604ef-23c2-4475-b64e-41fc6eb407dc︠

︡3c75dc79-c739-4d2e-8deb-b4516dd39398︡
︠b2c28255-b2bc-4733-b9a2-2c5a9f914d06︠

︡e386cc20-932c-46b2-b707-4f14816eec24︡
︠1d41c3e2-7eaa-4776-9d0c-b9ead9696e17s︠
set_random_seed(777) #I set the seed so that the same random numbers come up every time.
q = random_prime(2**100) ## The size of the prime controls the difficulty
g = Zmod(q).multiplicative_generator()
x = Zmod(q).random_element()
h = pow(g,x,q)
G = Zmod(q)
kpub_A = {'G':Zmod(q),'q':q,'g':g,'h':h}
kpriv_A = {'x':x}
print "Alice's public key:\n",kpub_A
print "Alice's private key:\n",kpriv_A
︡a0c88e54-6298-44ee-ad7a-ce7117656a74︡{"stdout":"Alice's public key:\n{'q': 59099614591155266561502224021, 'h': 47061840137518401563605044840, 'g': 2, 'G': Ring of integers modulo 59099614591155266561502224021}\n"}︡{"stdout":"Alice's private key:\n{'x': 58617751642861105080873037470}\n"}︡{"done":true}︡
︠bc80e2d8-e454-488f-a3d0-3f8e7819950fi︠
%md

Now Bob encrypts a message $m$ using ephemeral key $y$...
︡44fcb5a6-0824-4857-95b0-af36e93e2a09︡{"done":true,"md":"\nNow Bob encrypts a message $m$ using ephemeral key $y$..."}
︠597e3358-f3fd-49e1-9472-5bc3980c589f︠
y = kpub_A['G'].random_element() ## ephemeral key
c_1 = pow(kpub_A['g'],y,kpub_A['q']) ## c_1 = g**y mod q
s = pow(kpub_A['h'],y,kpub_A['q']) ## s = h**y mod q
m = ZZ(G.random_element())#the message
print "m = ",hex(ZZ(m))
c_2 = (m*s)%kpub_A['q']  ## c_2 = m*s mod q
ciphertext = (c_1,c_2)
print "y = %d, c_1 = %d, s = %d c_2 = %d\n"%(y,c_1,s,c_2)
print "ciphertext (c_1,c_2) = ",ciphertext
︡605f6f99-005a-4733-8105-c68922bd5a98︡{"stdout":"m =  3c6ee2c3587f6ba05ccf5f27\n"}︡{"stdout":"y = 12237851913445955665374134727, c_1 = 1861847164668332582362807801, s = 26965319895811554883077262668 c_2 = 33451184415922229898860033033\n\n"}︡{"stdout":"ciphertext (c_1,c_2) =  (1861847164668332582362807801, 33451184415922229898860033033)\n"}︡{"done":true}︡
︠36c539f1-5cb3-49d8-abb2-2910d92979f0s︠
print "A problem..."
print "The public key:",kpub_A
print "The ciphertext:",ciphertext
print "What's the message?"
print "(solution: %d)"%m
︡35b23ae7-7d3b-432f-8489-812b3d8533f9︡{"stdout":"A problem...\n"}︡{"stdout":"The public key: {'q': 59099614591155266561502224021, 'h': 47061840137518401563605044840, 'g': 2, 'G': Ring of integers modulo 59099614591155266561502224021}\n"}︡{"stdout":"The ciphertext: (1861847164668332582362807801, 33451184415922229898860033033)\n"}︡{"stdout":"What's the message?\n"}︡{"stdout":"(solution: 18703153287755470179761348391)\n"}︡{"done":true}︡
︠a452031a-c315-4200-98dc-4303862a2627i︠
%md

Now Alice uses her private key to decrypt the ciphertext $(c_1,c_2)$...
︡87eb4c56-afa3-444a-a467-ad37a6429208︡{"done":true,"md":"\nNow Alice uses her private key to decrypt the ciphertext $(c_1,c_2)$..."}
︠a817908d-8a28-4714-b089-a5df934f87e8︠
S_alice = pow(c_1,kpriv_A['x'],kpub_A['q']) ## S = c_1**x mod q
assert(s == S_alice)  ##Alice uses her private key to derive her version of the secret s
sinv = inverse_mod(ZZ(S_alice),ZZ(kpub_A['q'])) ## s inverse mod q
M = ZZ((sinv*c_2)%kpub_A['q']) ## M = c_2*s^(-1) mod q
print "M = ",hex(M) # the decrypted message
assert m==M
︡ff71009d-7433-481b-969e-56d717e9cc50︡{"stdout":"M =  3c6ee2c3587f6ba05ccf5f27\n"}︡{"done":true}︡
︠0d41fd73-c634-4770-bc9c-d14572c9126bs︠

︡7cb85807-8918-4ae5-b204-ad63691674f5︡{"done":true}︡
︠409a1fa8-ed41-4457-9b88-ca43bfeda9fes︠
︡761b2d32-e951-43b0-8458-4871b5011e53︡{"done":true}︡
︠3665fd05-7c0a-4323-97f0-01ad9a5cac04s︠


︡f17f548a-a73f-4a4e-8d08-a997d71288c3︡{"done":true}︡
︠e61c5132-c204-4f64-bdfc-5145d9d1b8db︠









