brackets = ""


def legal(brackets):
    brackets_match = {"(": ")"}
    a = "("
    legal = "()"

    open_stack = []

    for i in brackets:
        if i not in legal:
            brackets = brackets.replace(i, "")

    for i in brackets:
        if len(brackets) == 1:
            return "NO"
        if i in a:
            open_stack.append(i)
        else:
            try:
                if brackets_match[open_stack[-1]] == i:
                    open_stack.pop(-1)
            except IndexError:
                return "NO"
    else:
        if len(open_stack) == 0 and len(brackets) > 1 or len(brackets) == 0:
            return "YES"
        else:
            return "NO"


for i in range(int(input())):
    print(legal(input()))
