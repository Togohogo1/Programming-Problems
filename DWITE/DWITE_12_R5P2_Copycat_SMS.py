def twice(sms):
    for i in range(len(sms) - 1, 0, -1):
        if sms.endswith(sms[:i]):
            return sms + sms[i:]

    return sms*2


for _ in range(5):
    print(twice(input()))
