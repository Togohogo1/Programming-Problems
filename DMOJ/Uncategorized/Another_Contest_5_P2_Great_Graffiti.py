S = input()

if S == "DMOJ":
    print(0)
elif "DMO" in S or "DOJ" in S or "DMJ" in S or "MOJ" in S:
    print(1)
elif "DM" in S or "DO" in S or "DJ" in S or "MO" in S or "MJ" in S or "OJ" in S:
    print(2)
elif "D" in S or "M" in S or "O" in S or "J" in S:
    print(3)
