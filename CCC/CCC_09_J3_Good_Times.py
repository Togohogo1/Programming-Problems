def convert(time):
    TIM = int(f"{time:04d}"[:2])*60 + int(f"{time:04d}"[2:])

    times = {
        "in Ottawa": TIM,
        "in Victoria": TIM-180,
        "in Edmonton": TIM-120,
        "in Winnipeg": TIM-60,
        "in Toronto": TIM,
        "in Halifax": TIM+60,
        "in St. John's": TIM+90
    }

    for i in times:
        if times[i] <= 0:
            times[i] += 1440
        elif times[i] >= 1440:
            times[i] -= 1440

        print(int(str(f"{times[i]//60:02d}{times[i]%60:02d}")), str(i))


convert(int(input()))
