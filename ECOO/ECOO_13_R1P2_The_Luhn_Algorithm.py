def digit_sum(n):
    ds = 0

    for i in n:
        ds += int(i)

    return ds


def fr(n):
    f = 0

    for i in range(len(n)):
        if i % 2 == 1:
            f += int(n[i])

    return f


def snd(n):
    s = 0

    for i in range(len(n)):
        if i % 2 == 0:
            s += digit_sum(str(2*int(n[i])))

    return s


for i in range(5):
    bases = map(str, input().split())
    checks = ""

    for i in bases:
        i = i[::-1]

        if str(fr(i) + snd(i))[-1] == "0":
            checks += "0"
        else:
            checks += str(10 - int(str(fr(i) + snd(i))[-1]))

    print(checks)
