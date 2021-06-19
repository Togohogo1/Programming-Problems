nums = {"ABC": "2",
        "DEF": "3",
        "GHI": "4",
        "JKL": "5",
        "MNO": "6",
        "PQRS": "7",
        "TUV": "8",
        "WXYZ": "9"
}

for i in range(int(input())):
    number = list(input())
    new = ""

    for i in number:
        if i != "-":
            for j in nums:
                if i in j:
                    new += nums[j]
                    break
            else:
                new += i

    print(new[:3] + "-" + new[3:6] + "-" + new[6:10])
