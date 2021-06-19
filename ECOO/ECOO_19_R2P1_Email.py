for i in range(10):
    emails = set()

    for i in range(int(input())):
        email = input().lower()

        new = ""
        plus = False

        for i in email:
            if i == "+":
                plus = True

            if i == "@":
                new += email[email.index("@"):]
                break

            if not plus:
                if i not in {".", "+"}:
                    new += i

        emails.add(new)

    print(len(emails))
