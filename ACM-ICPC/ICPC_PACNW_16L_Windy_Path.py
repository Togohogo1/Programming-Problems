# Check for CW or CCW orientation ()
def orient(p1, p2, p3):
    if (p2[1]-p1[1])*(p3[0]-p2[0]) - (p3[1]-p2[1])*(p2[0]-p1[0]) < 0:
        return 1  # CCW
    return 0


# Returns the convex hull of the points passed in parameter
def convex_hull(points):
    conv_hull = []
    hull_idx = []

    t1 = 0
    t2 = 0

    while True:
        hull_idx.append(t2)
        t2 = (t1+1) % len(points)  # Break when loop back to starting (t2 == 0)

        # If point more CCW than previous, update `t2` to it
        for i in range(len(points)):
            if orient(points[t1], points[t2], points[i]) == 1:
                t2 = i
        t1 = t2  # Set t1 to t2, the most current CCW point, and add to hull next iteration

        if t2 == 0:
            break

    for i in hull_idx:
        conv_hull.append(points[i])

    return conv_hull


final_dir = ""
points = [[int(i) for i in input().split()] for _ in range(int(input()))]
sorted_points = list(sorted(points))

direction = f"_{input()}_"  # N - 2 directions, add space to front and back

# Start point, directions, and end point
for i in range(len(direction)):
    if i == 0:
        # Initialize temp as bottom left point of sorted array
        temp = sorted_points[0]

        final_dir += f"{points.index(temp)+1} "

    # Creates convex hull of current {points}, removes previous point from {points} and repeats
    elif i < len(direction)-1:
        if direction[i] == "R":
            # index(temp)+(-)1 to move to closest right(left) point from current point on current convex hull.
            curr = convex_hull(sorted_points)[(convex_hull(sorted_points).index(temp)+1) % len(convex_hull(sorted_points))]
            sorted_points.remove(temp)
            temp = curr  # Makes temp the next current point

            final_dir += f"{points.index(curr)+1} "

        elif direction[i] == "L":
            curr = convex_hull(sorted_points)[(convex_hull(sorted_points).index(temp)-1)]
            sorted_points.remove(temp)
            temp = curr

            final_dir += f"{points.index(curr)+1} "

    elif i == len(direction)-1:
        final_dir += f"{points.index(sorted_points[sorted_points.index(curr)-1])+1} "

print(final_dir[:-1])
