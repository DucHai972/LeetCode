class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        ret = []
        for x, y in points:
            if not ret or x > ret[-1][1]:
                ret.append([x, y])
                continue
            if x <= ret[-1][1]:
                ret[-1] = [max(x, ret[-1][0]), min(y, ret[-1][1])]

        return len(ret)
