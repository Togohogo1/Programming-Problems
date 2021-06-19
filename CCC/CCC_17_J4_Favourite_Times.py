count = 0

time_passed = int(input())


def arithcount(time, n):
    for i in range(0, (time + 1) % 720):
        new_time = int(str(f"{(720 + i) // 60:02d}{(720 + i) % 60:02d}"))
        if new_time >= 1300:
            new_time -= 1200

        new_time = str(new_time)
        if len(new_time) == 4:
            if int(new_time[3]) - int(new_time[2]) == int(new_time[2]) - int(new_time[1]) and int(new_time[2]) - int(new_time[1]) == int(new_time[1]) - int(new_time[0]):
                n += 1
        else:
            if int(new_time[2]) - int(new_time[1]) == int(new_time[1]) - int(new_time[0]):
                n += 1

    return n


print(arithcount(time_passed, count) + 31*(time_passed//720))
