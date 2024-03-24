class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        lmao = 0
        for i in range(1, len(nums)):
            if nums[i] == nums[lmao]:
                return nums[i]
            lmao += 1
        return -1
        
