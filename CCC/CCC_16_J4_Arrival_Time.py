a = list(map(int, input().split(":")))
t = a[0]*60 + a[1]

if 420 <= t <= 600:
    final = (t+840) // 2

elif 900 <= t <= 1140:
    final = (t+1380) // 2

elif abs(420 - t) <= 120:
    if (t - 300)*2 > 180:
        final = (5*t-780) // 2
    else:
        final = 2*t - 180

elif abs(900 - t) <= 120:
    final = 2*t - 660

else:
    final = t + 120

final %= 1440
print(f"{final // 60:02d}:{final % 60:02d}")
