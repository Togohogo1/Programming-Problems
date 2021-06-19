T_occur = False
D_occur = False
P_occur = False

T, D, P = map(int, input().split())

if T < -40:
    T_occur = True
if D >= 15:
    D_occur = True
if P > 50:
    P_occur = True

if T_occur and D_occur or T_occur and P_occur or D_occur and P_occur or T_occur and D_occur and P_occur:
    print("YES")
else:
    print("NO")
