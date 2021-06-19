def is_prime(number):
    if number > 1:
        for i in range(2, number):
            if (number % i) == 0:
                return 0
        else:
            return 1
    else:
        return 0


def print_primes(low, hi):
    b = 0

    for i in range(low, hi):
        b += is_prime(i)

    return b


for i in range(int(input())):
    lower, upper = map(int, input().split())
    print(print_primes(lower, upper))
