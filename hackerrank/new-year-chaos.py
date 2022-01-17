t = int(input())
for i in range(t):
    n = int(input())
    q = [int(x) for x in input().split(' ')]
    cur = len(q)
    sol = 0
    for x in range(cur-1, 0, -1):
        if q[x] == cur:
            cur -= 1
            continue
        for i in range(2,0,-1):
            if q[x-i] == cur:
                # swap people and increase bribe count
                d = q[x-i+1]
                q[x-i+1] = q[x-i]
                q[x-i] = d
                sol += 1
            if i == 1 and q[x] == cur:
                cur -= 1
                break
        else:
            print('Too chaotic')
            break
    else:
        print(sol)
