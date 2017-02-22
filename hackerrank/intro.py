# Enter your code here. Read input from STDIN. Print output to STDOUT

x, n = raw_input(), raw_input()
l = raw_input().split(' ')
for i, y in enumerate(l):
    if x == y:
        print i
        break
