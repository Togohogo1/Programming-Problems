N = int(input())

for i in range(N):
    s = input()

    if "C" in s and "M" in s:
        print("NEGATIVE MARKS")
    elif "C" in s or "M" in s:
        print("FAIL")
    else:
        print("PASS")
