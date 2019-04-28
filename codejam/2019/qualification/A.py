t = int(input())
for i in range(1, t + 1):
    n = input()
    a, b = '', ''
    for c in n:
        if c == '4':
            a += '2'
            b += '2'
        else:
            a += c
            b += '0'

    print("Case #{}: {} {}".format(i, int(a), int(b)))
