N, K = map(int, input().split())
seq = list(map(int, input().split()))
sorted_seq = list(reversed(sorted(seq)))

i = nk = 0

while nk != K:
    if seq == sorted_seq:
        break

    idx = seq.index(N-i)

    if seq[idx] != sorted_seq[idx]:
        seq[i], seq[idx] = seq[idx], seq[i]
        nk += 1

    i += 1

print(" ".join(map(str, seq)))
