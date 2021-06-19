msgList = []

Txtmsg = {
    "CU": "see you",
    ":-)": "I'm happy",
    ":-(": "I'm unhappy",
    ";-)": "wink",
    ":-P": "stick out my tongue",
    "(~.~)": "sleepy",
    "TA": "totally awesome",
    "CCC": "Canadian Computing Competition",
    "CUZ": "because",
    "TY": "thank-you",
    "YW": "you're welcome",
    "TTYL": "talk to you later"
}

while True:
    msg = input()

    if msg in Txtmsg:
        msgList.append(Txtmsg[msg])
    else:
        msgList.append(msg)

    if msg == "TTYL":
        break

for i in msgList:
    print(i)
