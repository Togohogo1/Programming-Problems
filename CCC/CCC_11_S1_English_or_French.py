num_t = 0
num_s = 0

N = int(input())

for i in range(N):
    sent = str(input())

    num_t += sent.count("t")
    num_t += sent.count("T")
    num_s += sent.count("s")
    num_s += sent.count("S")

if num_t > num_s:
    print("English")
else:
    print("French")
