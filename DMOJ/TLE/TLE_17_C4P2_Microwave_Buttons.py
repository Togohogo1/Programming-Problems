from pprint import pprint

time = list(map(int, input().split(":")))
buttons = list(map(str, input()))

default = [0, 0, 0]

alltimes = []
diff = []


def word(time):
    for i in time:
        for j in str(f"{i:02d}"):
            if j not in buttons:
                return False
    return True


def timecalc(time):
    return time[0]*3600 + time[1]*60 + time[2]


for i in range(1000000):
    if word(default):
        alltimes.append(default.copy())
        diff.append(abs(timecalc(time) - timecalc(default.copy())))

    default[2] += 1

    if default[2] == 100:
        default[1] += 1
        default[2] = 0

        if default[1] == 100:
            default[0] += 1
            default[1] = 0


t = alltimes[diff.index((min(diff)))]
print(f"{t[0]:02d}:{t[1]:02d}:{t[2]:02d}")
