class Solution:

    def contains(self, interval: List[int], x: int) -> bool:
        if x >= interval[0] and x <= interval[1]:
            return True
        return False
    
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ret = []
        #?: variable unpacking in python
        left = newInterval[0]
        right = newInterval[1]
        status = 'begin'

        if not intervals:
            return [newInterval]
        
        for interval in intervals:
            if status == 'begin':
                if right < interval[0]:
                    ret.append(newInterval)
                    status = 'end'
                elif left < interval[0]:
                    interval[0] = left
                    status = 'merge'
                elif self.contains(interval, left):
                    status = 'merge'
                ret.append(interval)
                if self.contains(interval, right):
                        status = 'end'
            elif status == 'merge':
                if right < interval[0]:
                    ret[-1][1] = right
                    ret.append(interval)
                    status = 'end'
                else:
                    ret[-1][1] = interval[1]
                    if self.contains(interval, right):
                        status = 'end'
            elif status == 'end':
                ret.append(interval)

        if status == 'begin':
            ret.append(newInterval)
        elif ret[-1][1] < right:
            ret[-1][1] = right

        return ret
