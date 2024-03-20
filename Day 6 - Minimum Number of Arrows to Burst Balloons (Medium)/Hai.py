class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort()
        prev = points[0]
        ans = 1

        for i, j in points[1:]:
            if i <= prev[1]:
                prev[1] = min(prev[1], j)
            else:
                ans += 1
                prev[1] = j
        return ans
        
