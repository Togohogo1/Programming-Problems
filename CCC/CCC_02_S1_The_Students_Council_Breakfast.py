combos = []

p = int(input())
g = int(input())
r = int(input())
o = int(input())
T = int(input())

for i in range(T//p+1):
    for j in range(T//g+1):
        for k in range(T//r+1):
            for l in range(T//o+1):
                if p * i + g * j + r * k + o * l == T:
                    print(f"# of PINK is {i} # of GREEN is {j} # of RED is {k} # of ORANGE is {l}")
                    combos.append(i + j + k + l)

print(f"Total combinations is {len(combos)}.")
print(f"Minimum number of tickets to print is {min(combos)}.")
