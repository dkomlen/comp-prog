import random


def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


def solve_case(xs):
    keys = set()
    ys = []
    i = 0
    while xs[i] == xs[i + 1]:
        i += 1
    k = gcd(xs[i], xs[i + 1])
    if i % 2 == 0:
        ys.append(xs[0] // k)
        keys.add(xs[0] // k)
    else:
        ys.append(k)
        keys.add(k)
        k = xs[0] // k

    for i, x in list(enumerate(xs))[1:]:
        ys.append(k)
        keys.add(k)
        k = x // k
        if i == len(xs) - 1:
            ys.append(k)
            keys.add(k)

    if len(keys) > 26:
        print(sorted(keys))
    alphabet = {key: chr(65 + i) for (i, key) in enumerate(sorted(keys))}
    return ''.join(map(lambda y: alphabet[y], ys))


def encrypt(msg):
    msg = msg.replace(' ', '')
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
              107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
              227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281]
    random.shuffle(primes)
    alphabet = {chr(65 + i): key for i, key in enumerate(sorted(primes[:26]))}
    replaced = list(map(lambda c: alphabet[c], msg))
    encrypted = []
    for i in range(1, len(replaced)):
        encrypted.append(replaced[i - 1] * replaced[i])
    return (encrypted, alphabet)


def debug():
    for i in range(10000):
        msg = list('ABCDEFGHIJKLMNOPQRSTUVWYXZF' * 10)
        random.shuffle(msg)
        msg = ''.join(msg)
        enc, alphabet = encrypt(msg)
        dec = solve_case(enc)
        if (msg != dec):
            print(msg)
            print(dec)
            print(enc)
            print(alphabet)
            exit(1)


def solve():
    t = int(input())
    for case in range(1, t + 1):
        n, l = [int(x) for x in input().split(' ')]
        xs = [int(x) for x in input().split(' ')]
        sol = solve_case(xs)
        print("Case #{}: {}".format(case, sol))


solve()
