import sys
input = sys.stdin.readline


# import accumulate takes too much memory
def accumulate(A):
    n = len(A)
    P = [0] * (n + 1)
    for k in range(1, n + 1):
        P[k] = P[k - 1] + A[k - 1]
    return P

count = 0
length = 0
lower_bound = 0

cups, fill = map(int, input().split())
cuplist = [0] * (cups + 2)

for i in range(fill):
    lower, upper, chocs = map(int, input().split())
    cuplist[lower] += chocs
    cuplist[upper+1] -= chocs

totalcup = int(input())

cuplist = list(accumulate(cuplist))
cuplist.pop(0)

cuphead = list(accumulate(cuplist))  # Prefix sum array for cuplist
cuphead.pop(0)

# A brute force method will force the upper bound to go back to l, therefore resulting in O(N^2)
# Though it may be 2 for loops, it is actually 2 counters
for upper_bound in range(1, cups + 1):
    while cuphead[upper_bound] - cuphead[lower_bound] > totalcup:
        lower_bound += 1

    count = max(count, upper_bound - lower_bound)

print(count)
