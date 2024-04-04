class Solution:
    def maxDepth(self, s: str) -> int:  
        stack = 0
        count, max_count = 0, 0
        for i in s:
            if i == "(":
                count -= 1
            elif i == ")":
                count += 1
            max_count = min(count, max_count)

        return max_count*(-1)     


        

