from functools import cmp_to_key

def cmp(frac1, frac2):
    num1 = frac1[0] * frac2[1]
    num2 = frac2[0] * frac1[1]

    if num1 < num2:
        return -1
    elif num2 < num1:
        return 1
    elif frac1[0] < frac2[0]:
        return -1
    else:
        return 1

fracs = []
fracs.sort(key=cmp_to_key(cmp))