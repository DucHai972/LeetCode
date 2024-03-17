class Solution:
    def insert(self, intervals: List[List[int]], new: List[int]) -> List[List[int]]:
        if not intervals:
            return [new]
        ret = []
        inserted = False
        for s, e in intervals:
            if e < new[0]:
                ret.append([s, e])
            elif s > new[1]:
                if not inserted:
                    ret.append(new)
                    inserted = True
                ret.append([s, e])
            else:
                new = [min(s, new[0]), max(e, new[1])]
        if not inserted:
            ret.append(new)
        return ret
