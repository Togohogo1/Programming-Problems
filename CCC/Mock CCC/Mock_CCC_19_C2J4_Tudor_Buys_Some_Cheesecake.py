candles_need = input()
candles_have = input()

li_need = [0]*26
li_have = [0]*26

for i in candles_need:
    li_need[ord(i)-65] += 1

for i in candles_have:
    li_need[ord(i)-65] -= 1
    if li_need[ord(i)-65] < 0:
        li_need[ord(i)-65] = 0

print(sum(li_need))
