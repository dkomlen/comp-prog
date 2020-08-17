
socks = {}
n = int(input())
xs = [int(x) for x in input().split(' ')]
sol = 0

for x in xs:
    socks[x] = socks.get(x, 0) + 1
for (s, c) in socks.items():
    sol += c//2
print(sol)