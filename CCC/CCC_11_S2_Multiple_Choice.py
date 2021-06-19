count = 0

wrong = []
correct = []

N = int(input())
for i in range(N):
    ans = input()
    wrong.append(ans)

for i in range(N):
    ans = input()
    correct.append(ans)

for i in range(N):
    if wrong[i] == correct[i]:
        count += 1

print(count)
