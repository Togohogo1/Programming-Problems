notes = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]

for _ in range(int(input())):
    r, f, s, t = map(str, input().split())
    d1 = (notes.index(f)-notes.index(r)) % 12
    d2 = (notes.index(s)-notes.index(f)) % 12
    d3 = (notes.index(t)-notes.index(s)) % 12

    if [d1, d2, d3] == [4, 3, 3]:
        print("root")
    elif [d1, d2, d3] == [3, 3, 2]:
        print("first")
    elif [d1, d2, d3] == [3, 2, 4]:
        print("second")
    elif [d1, d2, d3] == [2, 4, 3]:
        print("third")
    else:
        print("invalid")
