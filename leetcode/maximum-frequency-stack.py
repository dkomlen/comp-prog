import heapq

class FreqStack:

    def __init__(self):
        self.heap = [] # [(-freq, -push_ctr, num)]
        self.fq = {} # { num: freq }
        self.push_ctr = 0

    def push(self, x: int) -> None:
        fq = self.fq.get(x, 0) + 1
        self.fq[x] = fq
        self.push_ctr += 1
        heapq.heappush(self.heap, (-fq, -self.push_ctr, x))

    def pop(self) -> int:
        (fq, ctr, x) = heapq.heappop(self.heap)
        fq = self.fq[x] - 1
        self.fq[x] = fq
        return x

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()