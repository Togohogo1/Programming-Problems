inp = input().lower()

if not inp.startswith("darcy"):
    print("other user")
    raise SystemExit

if not inp.endswith("liu"):
    print("other user")
    raise SystemExit

if inp == "darcy_liu":
    print("real")
    raise SystemExit

inp = inp[5:-3]
if set(inp) == {"_"}:
    print("fake")
else:
    print("other user")
