from pprint import pprint


def xor(a, b):
    li_xor = []

    for i in range(len(a)):
        li_xor.append(a[i] ^ b[i])

    return li_xor


R = int(input())
C = int(input())

board = []
combos = []

for i in range(R):
    board.append(list(map(int, input().split())))

board.reverse()
board_temp = board.copy()

for i in range(R-1, 0, -1):
    for j in range(i-1, -1, -1):
        board_temp[j] = xor(board_temp[j], board_temp[j+1])

    combos.append(str(board_temp[0]))
    board_temp = board.copy()

combos.append(str(board[0]))

print(len(set(combos)))
