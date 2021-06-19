lines = []

for _ in range(int(input())):
    lines.append(input())

LEGAL = frozenset("1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM")


def compress(string):
    buffer = ""

    for char in string:
        if char in LEGAL:
            buffer += char
        else:
            if buffer:
                if len(buffer) == 4:
                    yield "****"
                else:
                    yield buffer

                buffer = ""

            yield char

    if buffer:
        if len(buffer) == 4:
            yield "****"
        else:
            yield buffer


for line in lines:
    print("".join(compress(line)))
    print()
