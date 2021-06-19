wpns = ["B", "F", "T", "L", "C"]

n = str(input())

for i in range(5):
    if "B" in wpns and "B" in n:
        wpns.remove("B")
    if "F" in wpns and "F" in n:
        wpns.remove("F")
    if "T" in wpns and "T" in n:
        wpns.remove("T")
    if "L" in wpns and "L" in n:
        wpns.remove("L")
    if "C" in wpns and "C" in n:
        wpns.remove("C")

if "B" in n and "F" in n and "T" in n and "L" in n and "C" in n:
    print("NO MISSING PARTS")
else:
    for i in wpns:
        print(i)
