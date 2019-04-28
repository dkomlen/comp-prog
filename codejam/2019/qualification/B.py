t = int(input())
for i in range(1, t + 1):
    n = int(input())
    p = input()
    p = p.replace('E','x')
    p = p.replace('S','E')
    p = p.replace('x','S')

    print("Case #{}: {}".format(i, p))
