import math

distance_x = distance_y = 0
distance_final = direction_final = 0

for i in range(int(input())):
    magnitude, direction = map(int, input().split())

    direction %= 360
    direction *= math.pi / 180

    if 0 < direction <= 90:  # Q1
        distance_x += magnitude * math.sin(direction % 90)
        distance_y += magnitude * math.cos(direction % 90)
    elif 90 < direction <= 180:  # Q2
        distance_x += magnitude * math.sin(direction % 90)
        distance_y -= magnitude * math.cos(direction % 90)
    elif 180 < direction <= 270:  # Q3
        distance_x -= magnitude * math.sin(direction % 90)
        distance_y -= magnitude * math.cos(direction % 90)
    else:  # Q4
        distance_x -= magnitude * math.sin(direction % 90)
        distance_y += magnitude * math.cos(direction % 90)

distance_final = math.sqrt(distance_x ** 2 + distance_y ** 2)

if distance_x > 0 and distance_y > 0:  # Q1
    direction_final = math.asin((distance_x / distance_final)) * 180 / math.pi
elif distance_x > 0 and distance_y < 0:  # Q2
    direction_final = abs(math.asin((distance_x / distance_final)) * 180) / math.pi + 90
elif distance_x < 0 and distance_y < 0:  # Q3
    direction_final = abs(math.asin((distance_x / distance_final)) * 180) / math.pi + 180
elif distance_x < 0 and distance_y > 0:  # Q4
    direction_final = abs(math.asin((distance_x / distance_final)) * 180) / math.pi + 270

print(f"{distance_final:.0f}", f"{direction_final:.0f}")
