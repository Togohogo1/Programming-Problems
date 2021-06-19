a, b = map(int, input().split())


def primeFactors(n):
    primes = []

    while n % 2 == 0:
        primes.append(2)
        n //= 2

    for i in range(3, int(n**0.5+1), 2):
        while n % i == 0:
            primes.append(i)
            n //= i

    if n > 2:
        primes.append(n)

    return primes


def fact(b, a):
    count = 0

    while b % a == 0:
        count += 1
        b //= a

    return count


ans = 0.0
primes = primeFactors(a)

for i in range(max(primes), b+1, max(primes)):
    ans += fact(i, max(primes))

ans //= primes.count(max(primes))

print(int(ans))
