N = int(input())
Mole = input()

for i in Mole:
    if i not in "ACGTU":
        print("neither")
        break
else:
    if "U" not in Mole and "T" not in Mole:
        print("both")
    elif "U" in Mole and "T" in Mole:
        print("neither")
    elif "U" in Mole and "T" not in Mole:
        print("RNA")
    elif "U" not in Mole and "T" in Mole:
        print("DNA")
