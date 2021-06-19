temp = []

orig = input()
anagram = input()

# Remove the *'s:
for i in anagram:
    if i == "*":
        anagram = anagram.replace(i, "")
        temp.append(i)  # Asterices store in list

# If anagram in orig, remove both
for i in anagram:
    if i in orig:
        anagram = anagram.replace(i, "", 1)
        orig = orig.replace(i, "", 1)

if len(orig) == len(temp):  # Is ana, *'s left = letters left in orig
    print("A")
else:
    print("N")
