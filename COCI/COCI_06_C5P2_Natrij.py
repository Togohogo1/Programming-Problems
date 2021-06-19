t1 = list(map(int, input().split(":")))
t2 = list(map(int, input().split(":")))

m1 = t1[0]*3600 + t1[1]*60 + t1[2]
m2 = t2[0]*3600 + t2[1]*60 + t2[2]

tot = (m2-m1) % 86400
h = (tot//3600)

tot -= (tot//3600) * 3600
m = (tot//60)

tot -= (tot//60)*60
s = tot

fin = f"{h:02d}:{m:02d}:{s:02d}"
print(fin if fin != "00:00:00" else "24:00:00")
