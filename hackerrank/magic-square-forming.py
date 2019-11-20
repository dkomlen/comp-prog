from copy import deepcopy

def rotate(s):
    sr = deepcopy(s)
    for i in range(len(s)):
        sr[i] = [x[i] for x in s][::-1]
    for i in range(len(s)):
        s[i] = sr[i]
    return s

def flip(s):
    fs = [[],[],[]]
    temp = s[2]
    fs[2] = s[0]
    fs[0] = temp
    fs[1] = s[1]
    return fs


def iter_magic_squares():
    s = [[8, 3, 4],
         [1, 5, 9],
         [6, 7, 2]]

    for x in range(8):
        yield rotate(s)
        yield flip(s)


def formingMagicSquare(s):
    dif = 1000
    for sq in iter_magic_squares():
        d = 0
        for row in range(3):
            for col in range(3):
                d += abs(s[row][col] - sq[row][col])
        dif = min(dif, d)
    return dif


if __name__ == '__main__':
    s = [[4, 5, 8],
         [2, 4, 1],
         [1, 9, 7]]
    print(formingMagicSquare(s))
