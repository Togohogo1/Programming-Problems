n = input()

if n.count(":-)") > n.count(":-("):
    print("happy")
elif n.count(":-)") < n.count(":-("):
    print("sad")
elif n.count(":-)") == n.count(":-(") and n.count(":-)") > 0 or n.count(":-(") > 0:
    print("unsure")
else:
    print("none")
