'''
Given a string, return a string where for every char in the original, there
are two chars.
'''

def double_char(str):
    a = ""

    for i in range(len(str)):
        a += str[i]*2

    return a
