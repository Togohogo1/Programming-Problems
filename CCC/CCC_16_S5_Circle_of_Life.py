N, T = map(int, input().split())

binary = bin(T)[2:]
binlen = len(binary)

cells = list(map(int, input()))
hold = cells.copy()

for i in range(binlen-1, -1, -1):
    if binary[i] == "1":
        offset = 2**(binlen - i - 1)

        for j in range(N):
            cells[j] = hold[(j-offset) % N] ^ hold[(j+offset) % N]

        hold = cells.copy()

print(*hold, sep="")
