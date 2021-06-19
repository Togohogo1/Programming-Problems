n = ""
t = 0

cities = []
temps = []

while n != "Waterloo":
    n, t = map(str, input().split())

    cities.append(n)
    temps.append(int(t))

print(cities[temps.index(min(temps))])
