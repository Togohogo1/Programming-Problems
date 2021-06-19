t = int(input())
s = int(input())
h = int(input())

for i in range(t):
    print(("*" + " "*s)*2 + "*")

print("*"*len(("*" + " "*s)*2 + "*"))

for i in range(h):
    print(" "*(len(s*"*" + "*")) + "*")
