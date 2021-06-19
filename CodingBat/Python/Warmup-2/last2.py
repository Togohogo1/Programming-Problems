'''
Given a string, return the count of the number of times that a substring
length 2 appears in the string and also as the last 2 chars of the string, so
"hixxxhi" yields 1 (we won't count the end substring).
'''

def last2(str):
    count = 0

    for i in range(len(str)-1):
        if str[i] + str[i+1] == str[-2:]:
            count += 1

    if len(str) > 1:
        return count - 1

    return 0
