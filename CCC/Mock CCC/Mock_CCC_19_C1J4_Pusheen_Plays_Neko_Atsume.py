import operator

food_count = {
    "Deluxe Tuna Bitz":0,
    "Bonito Bitz":0,
    "Sashimi":0,
    "Ritzy Bitz":0
}

for i in range(int(input())):
    food = input()
    food_count[food] += 1

sorted_food = sorted(food_count.items(), key=operator.itemgetter(1), reverse = True)

for i in sorted_food:
    if i[1] != 0:
        print(i[0], i[1])
