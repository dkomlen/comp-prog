class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda interval: interval[1])
        last_end = intervals[0][1]
        max_ints = 1
        for interval in intervals:
            if interval[0] >= last_end:
                last_end = interval[1]
                max_ints += 1
                
        return len(intervals) - max_ints

