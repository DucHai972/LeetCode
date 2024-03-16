class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        temp = 0
        stack = []
        for i in nums:
            if i == 0:
                temp -= 1
                stack.append(temp)
            else:
                temp += 1
                stack.append(temp)

        first_appear = {}
        longest = {}
        first_appear[0] = 0
        for i, val in enumerate(stack):
            if val not in first_appear:
                first_appear[val] = i+1
            if val in first_appear:
                if val not in longest:
                    longest[val] = i - first_appear[val]
                elif i - first_appear[val] > longest[val]:
                    longest[val] = i - first_appear[val]
        return max(longest.values()) + 1
