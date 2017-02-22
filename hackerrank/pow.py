M = 10**9 + 7

def pow(a,b):
    if b == 0:
        return a
    x = []
    sol = a
    while b:
        if b % 2:
            x.append(0)
            b = b - 1
        else:
            x.append(1)
            b = b / 2
    for i in reversed(x[:-1]):
        if i:
            sol = (sol * sol) % M
        else:
            sol = (sol * a) % M
    return sol % M

n = int(raw_input())
for i in xrange(n):
    a,b = map(lambda a: long(a), raw_input().split(" "))
    print pow(a%M,b)
    
