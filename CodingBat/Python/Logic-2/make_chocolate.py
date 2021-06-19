'''
We want make a package of goal kilos of chocolate. We have small bars (1 kilo
each) and big bars (5 kilos each). Return the number of small bars to use,
assuming we always use big bars before small bars. Return -1 if it can't be
done.
'''

def make_chocolate(small, big, goal):
    if small + big*5 == goal:
        return small
    elif small + big*5 < goal:
        return -1
    else:
        if small >= goal % 5:
            return goal - min(big*5, goal//5*5)

        return -1
