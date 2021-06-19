def plr_remv(word):
    return word[:-1] if word and word[-1] == "s" else word


def punc_remv(word):
    return word[:-1] if word and word[-1] in {".", "?"} else word


def neg_switch(subj):
    return "don't" if subj in {"I", "you"} else "doesn't"


def pred_switch(subj, pred):
    return f"{pred}" if subj in {"I", "you"} else f"{pred}s"


def subj_switch(subj):
    return {"I": "you", "you": "I"}.get(subj, subj)


def gen_stmt(sent):
    subj = sent.pop(0)
    isNeg = False

    if subj == "nobody":
        subj = "everybody"
        isNeg = True

    if sent[0] in {"don't", "doesn't"}:
        sent.pop(0)
        isNeg = True

    pred = plr_remv(punc_remv(sent.pop(0)))
    obj = punc_remv(" ".join(sent))

    return [subj, pred, obj, isNeg]


def gen_does(sent):
    sent.pop(0)
    subj = sent.pop(0)
    pred = punc_remv(sent.pop(0))
    obj = punc_remv(" ".join(sent))

    return [subj, pred, obj]


def gen_who(sent):
    sent.pop(0)
    pred = plr_remv(punc_remv(sent.pop(0)))
    obj = punc_remv(" ".join(sent))

    return [pred, obj]


def gen_what(sent):
    return sent[2]


def find_does(arr, ques):
    for i in arr:
        temp_subj = subj_switch(ques[0])

        if i[:3] == ques:
            if i[-1]:
                print(f"no, {temp_subj} {neg_switch(temp_subj)} {i[1]} {i[2]}".strip() + ".")
            else:
                print(f"yes, {temp_subj} {pred_switch(temp_subj, i[1])} {i[2]}".strip() + ".")
            return

        elif i[0] == "everybody" and i[1:3] == ques[1:3]:
            if i[-1]:
                print(f"no, {temp_subj} {neg_switch(temp_subj)} {i[1]} {i[2]}".strip() + ".")
            else:
                print(f"yes, {temp_subj} {pred_switch(temp_subj, i[1])} {i[2]}".strip() + ".")
            return

    print("maybe.")


def find_who(arr, ques):
    comb = ""
    temp = []

    for i in arr:
        temp_subj = subj_switch(i[0])

        if i[1:3] == ques:
            if i[0] == "everybody":
                if i[-1]:
                    print(f"nobody {pred_switch(temp_subj, ques[0])} {ques[1]}".strip() + ".")
                else:
                    print(f"everybody {pred_switch(temp_subj, ques[0])} {ques[1]}".strip() + ".")
                return

            elif not i[-1]:
                temp.append(temp_subj)

    if len(temp) == 0:
        print("I don't know.")
    elif len(temp) == 1:
        print(f"{temp[-1]} {pred_switch(temp[-1], ques[0])} {ques[1]}".strip() + ".")
    else:
        for i in temp[:-1]:
            comb += f"{i}, "

        print(f"{comb[:-2]} and {temp[-1]} {ques[0]} {ques[1]}".strip() + ".")


def find_what(arr, ques):
    comb = ""
    temp = []
    temp_subj = subj_switch(ques)

    for i in arr:
        if i[0] == "everybody" or i[0] == ques:
            if i[-1]:
                phrase = f"{neg_switch(temp_subj)} {i[1]} {i[2]}".strip() + ", "

                if phrase not in temp:
                    temp.append(phrase)

            else:
                phrase = f"{pred_switch(temp_subj, i[1])} {i[2]}".strip() + ", "

                if phrase not in temp:
                    temp.append(phrase)

    if len(temp) == 0:
        print("I don't know.")
    elif len(temp) == 1:
        print(f"{temp_subj} {temp[-1][:-2]}.")
    else:
        for i in temp[:-1]:
            comb += i

        print(f"{temp_subj} {comb[:-1]} and {temp[-1][:-2]}.")


def is_contr(all_sent):
    for i in all_sent:
        for j in all_sent:
            if i != j:
                if i[:3] == j[:3] and i[-1] != j[-1]:
                    return True
                elif i[0] == "everybody" and i[1:3] == j[1:3] and i[-1] != j[-1]:
                    return True

    return False


def main():
    for i in range(int(input())):
        print(f"Dialogue #{i+1}:")
        arr = []

        while True:
            sent = input()

            if sent[-1] == ".":
                arr.append(gen_stmt(sent.split()))
            elif sent[-1] == "!":
                print(f"{sent}\n")
                break
            else:
                print(sent)
                ques = sent.split()

                if is_contr(arr):
                    print("I am abroad.")
                else:
                    if ques[0] in {"does", "do"}:
                        find_does(arr, gen_does(ques))
                    elif ques[0] == "who":
                        find_who(arr, gen_who(ques))
                    else:
                        find_what(arr, gen_what(ques))

                print()


main()
