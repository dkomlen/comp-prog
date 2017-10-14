if __name__ == "__main__":
   n = int(raw_input())
   sol = 0
   for i in xrange(n):
      row = [int(x) for x in raw_input().strip().split(' ')]
      sol += row[i] - row[n - 1 - i]
   print abs(sol)