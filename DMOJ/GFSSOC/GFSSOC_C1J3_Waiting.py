t1 = list(map(int, input().split(":")))
t2 = list(map(int, input().split(":")))

a = t1[0]*3600 + t1[1]*60 + t1[2]
b = t2[0]*3600 + t2[1]*60 + t2[2]

print(b - a)
