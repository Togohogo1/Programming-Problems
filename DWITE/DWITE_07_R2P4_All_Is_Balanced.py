brackets = ""

brackets_match = {"(": ")", "{": "}", "[": "]"}
open_stack = []

for i in range(5):
    brackets = input()

    for i in brackets:
        if i not in "({[)}]":
            brackets = brackets.replace(i, "")

    for i in brackets:
        if len(brackets) == 1:
            print("not balanced")
            break

        if i in "({[":
            open_stack.append(i)
        else:
            try:
                if brackets_match[open_stack[-1]] == i:
                    open_stack.pop(-1)
            except IndexError:
                print("not balanced")
                break
    else:
        if len(open_stack) == 0 and len(brackets) > 1 or len(brackets) == 0:
            print("balanced")
        else:
            print("not balanced")
