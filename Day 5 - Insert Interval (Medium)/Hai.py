class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        i = len(intervals)
        result = []
        n = 0

        while n < i and intervals[n][1] < newInterval[0]:
            result.append(intervals[n])
            n += 1

        while n < i and intervals[n][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[n][0])
            newInterval[1] = max(newInterval[1], intervals[n][1])
            n += 1
        
        result.append(newInterval)

        while n < i:
            result.append(intervals[n])
            n += 1

        return result
