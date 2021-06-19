primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

for i in range(5):
    c = 0
    n = int(input())

    if n in primes:
        print(0)
    else:
        for i in primes:
            while n % i != 1:
                n //= i
                c += 1

            if n == 0:
                break

        print(c)
