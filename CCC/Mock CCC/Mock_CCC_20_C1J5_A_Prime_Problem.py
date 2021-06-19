import math


def isprime(n):
    if n in {0, 1}:
        return False

    for i in range(2, int(math.sqrt(n)+1)):
        if n % i == 0:
            return False

    return True


# nxt_nextprime(2) = 2
def curr_nextprime(n):
    while True:
        if isprime(n):
            break

        n += 1

    return n


# nxt_nextprime(2) = 3
def nxt_nextprime(n):
    while True:
        n += 1
        if isprime(n):
            break

    return n


allcases = []

# At least len of D, at least value of N
D, N = map(int, input().split())

# If can fit
if len(str(N)) - D >= D:
    # Loop through all the prefixes (and suffixes) possible
    for i in range(D, len(str(N))-D+1):
        full_sfx = str(N)[i:]

        pfx = int(str(N)[:i])
        sfx = int(str(N)[i:])

        if isprime(pfx):
            # If sfx does not need to be carried
            if len(str(curr_nextprime(sfx))) == len(str(sfx)):

                # Case where sfx starts with 0's
                if len(str(sfx)) < len(full_sfx):
                    allcases.append(int(f"{curr_nextprime(pfx)}{curr_nextprime(10**(len(str(full_sfx))-1))}"))
                else:
                    allcases.append(int(f"{curr_nextprime(pfx)}{curr_nextprime(sfx)}"))

            # If sfx needs to be carried
            else:
                if len(str(sfx)) < len(full_sfx):
                    allcases.append(int(f"{curr_nextprime(pfx)}{curr_nextprime(10**(len(str(full_sfx))-1))}"))
                else:
                    allcases.append(int(f"{nxt_nextprime(pfx)}{curr_nextprime(10**(len(str(sfx))-1))}"))

        # If pfx is a composite number
        else:
            if len(str(sfx)) < len(full_sfx):
                allcases.append(int(f"{curr_nextprime(pfx)}{curr_nextprime(10**(len(str(full_sfx))-1))}"))
            else:
                allcases.append(int(f"{curr_nextprime(pfx)}{curr_nextprime(10**(len(str(sfx))-1))}"))

# If cannot fit
else:
    allcases.append(int(f"{curr_nextprime(10**(D-1))}{curr_nextprime(10**(D-1))}"))

print(min(allcases))
