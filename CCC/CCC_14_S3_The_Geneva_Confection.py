carslist = []
carlist = []

for i in range(int(input())):
    N = int(input())

    for i in range(N):
        car = int(input())
        carlist.append(car)

    carslist.append(carlist)
    carlist = []

for i in carslist:
    branch = []

    # Everytime a cart can be transported, current updates by 1 (next)
    current = 1

    while True:
        if len(i) > 0:
            # If it is the one
            if i[-1] == current:
                current += 1
                i.pop()

            # Any cars left?
            elif len(branch) > 0:
                if branch[-1] == current:  # See if there are any more cars to be sent to lake
                    current += 1
                    branch.pop()
                else:  # If not, send to the branch
                    branch.append(i.pop())

            # Straight up first one can't be sent to the lake
            else:
                branch.append(i.pop())

        # If the are cars in the branch and no cars in the mountains
        elif len(branch) > 0:
            if branch[-1] == current:  # If the car in the branch can go in the lake
                current += 1
                branch.pop()
            else:  # Otherwise, cannot complete recipe
                print("N")
                break

        # Everything can be put in the lake
        else:
            print("Y")
            break
