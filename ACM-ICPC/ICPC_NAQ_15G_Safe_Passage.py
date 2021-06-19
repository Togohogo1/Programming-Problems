def seg(li):
    ans = 0

    for i in range(len(li)-1, -1, -2):
        ans += li[i]

    return ans + len(li)//2*(ppl[0]+ppl[1]*2) + ppl[0] + ppl[1]


def cycle(li):
    ans = 0

    for i in li[2:]:
        ans += i

    return ans + (len(li[2:])-1)*ppl[0]


def default(li):
    ans = 0

    if len(li) in {1, 3}:
        return sum(li)
    elif len(li) == 2:
        return max(li)
    else:
        if len(li) % 2 == 0:
            for i in range(len(li)-1, 3, -2):
                ans += li[i] + 2*li[1] + li[0]

            return ans + li[0] + 3*li[1] + li[3]
        else:
            for i in range(len(li)-1, 3, -2):
                ans += li[i] + 2*li[1] + li[0]

            return ans + li[0] + li[1] + li[2]


slowest = True

ppl = list(map(int, input().split()))[1:]
ppl.sort()

if len(ppl) > 3:
    for i in range(len(ppl)-1, 1, -1):
        if ppl[0] + ppl[i] <= 2*ppl[1]:
            slowest = False
            break

if slowest:
    print(default(ppl))
else:
    if len(ppl[i:]) % 2 == 0:
        print(seg(ppl[i:]) + cycle(ppl[:i]))
    else:
        print(seg(ppl[i+1:]) + cycle(ppl[:i+1]))
