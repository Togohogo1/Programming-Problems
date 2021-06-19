def oper(op, a, b):
    op = str(op)
    a = float(a)
    b = float(b)

    if op == "*":
        return a * b
    elif op == "/":
        return a / b
    elif op == "+":
        return a + b
    elif op == "-":
        return a - b
    elif op == "%":
        return a % b
    elif op == "^":
        return a**b


operation = "*/+-%^"
instack = []

post = list(input().split())

for i in range(len(post)):
    if post[i] in operation:
        instack.append(oper(post[i], instack.pop(-2), instack.pop(-1)))
    else:
        instack.append(post[i])

print(float(instack[0]))
