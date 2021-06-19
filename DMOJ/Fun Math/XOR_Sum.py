def convert_min(li, c):
    for i in li:
        c ^= i

    return c


def convert_max(li, c):
    for i in li:
        c += i

    return c


temp = 0

N = int(input())
nums = list(map(int, input().split()))

print(convert_max(nums, temp) - convert_min(nums, temp))
