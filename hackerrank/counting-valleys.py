n = int(input())
xs = input()
lvl = 0
valley = False
sol = 0
for x in xs:
    if lvl == 0:
        if x == 'D':
            valley = True
        else:
            valley = False
    lvl += 1 if x == 'U' else -1
    if valley and lvl == 0:
        sol += 1
print(sol)