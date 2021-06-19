'''
Return the number of times that the string "code" appears anywhere in the
given string, except we'll accept any letter for the 'd', so "cope" and
"cooe" count.
'''

def count_code(str):
    legal = "qwertyuiopasdfghjklzxcvbnm"
    count = 0

    for i in legal:
        count += str.count("co" + i + "e")

    return count
