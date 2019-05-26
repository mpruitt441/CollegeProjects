︠1f0562a7-40e8-4d40-bec1-6b0b340a8ee4s︠
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
print alicesecret
︡8b2fce55-111e-451d-8078-517779c379f3︡{"stdout":"614772783048953284935918141383863650749484188596493739985464\n"}︡{"stdout":"1296973488537025976206377650482441286232171243283807551898335\n"}︡{"stdout":"True\n"}︡{"stdout":"1114843307672854130823153934546641163632309419764450970048486\n"}︡{"done":true}︡









