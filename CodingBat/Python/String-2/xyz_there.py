'''
Return True if the given string contains an appearance of "xyz" where the xyz
is not directly preceeded by a period (.). So "xxyz" counts but "x.xyz" does
not.
'''

def xyz_there(str):
    b = False

    str = "_" + str

    if len(str) > 3:
        for i in range(len(str)-3):
            if str[i] != "." and str[i+1:i+4] == "xyz":
                b = True

    return b
