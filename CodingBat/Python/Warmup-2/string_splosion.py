'''
Given a non-empty string like "Code" return a string like "CCoCodCode".
'''

def string_splosion(str):
    b = ""

    for i in range(len(str)+1):
        b += str[:i]

    return b
