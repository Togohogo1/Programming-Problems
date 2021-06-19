from itertools import accumulate

count = 0

students, submit_times = map(int, input().split())
points = list(map(int, input().split()))

points_final = [0] * (students + 1)

for i in range(submit_times):
    lower, upper = map(int, input().split())
    points_final[lower - 1] += 1
    points_final[upper] -= 1

points_final = list(accumulate(points_final))[:-1]

points.sort(reverse=True)
points_final.sort()

for i in range(students):
    count += points[i]*points_final[i]

print(count)
