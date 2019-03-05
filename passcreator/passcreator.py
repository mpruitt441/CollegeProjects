import random
import string
import pyperclip

def shuffle(shuffles):
    index = 0
    while index < shuffles:
        random.shuffle(abet)
        index += 1
    index = 0
    shuffles = random.randint(0,255)
    while index < shuffles:
        random.shuffle(cabet)
        index += 1
    index = 0
    shuffles = random.randint(0,255)
    while index < shuffles:
        random.shuffle(digits)
        index += 1
    index = 0
    shuffles = random.randint(0,255)
    while index < shuffles:
        random.shuffle(symbols)
        index += 1

def getPassword():
    size = random.randint(8,16)
    password = []*size
    passList = [abet,cabet,digits,symbols]
    i = 0
    while i < size:
            i += 1
            nextChar = random.choice(passList)
            password.append(random.choice(nextChar))
    pw = ''.join(password)
    print(pw)
    pyperclip.copy(pw)



shuff = random.randint(0,255)
abet = list(string.ascii_lowercase)
cabet = list(string.ascii_uppercase)
digits = list(string.digits)
symbols = ["!","@","#","$","%","$","%","^","^","&","*","(",")"]
shuffle(shuff)
getPassword()


