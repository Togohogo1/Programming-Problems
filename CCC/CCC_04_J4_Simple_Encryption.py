new = ""
shift = {}

key = input()
word = input()

for i in range(len(key)):
    shift[i] = ord(key[i]) - 65

for i in word:
    if i in "QWERTYUIOPASDFGHJKLZXCVBNM":
        new += i

for i in range(len(new)):
    if ((ord(new[i]) - 64 + shift[i % len(key)]) % 26) + 64 != 64:
        print(chr(((ord(new[i]) - 64 + shift[i % len(key)]) % 26) + 64), end="")
    else:
        print("Z", end="")
