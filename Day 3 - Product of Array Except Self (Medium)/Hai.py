class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [1] * len(nums)
        suffix = [1] * len(nums)

        for i in range(len(nums)):
            if (i == 0):
                prefix[i] = nums[i]
                continue
            prefix[i] = nums[i] * prefix[i-1]
                
        for i in range(len(nums)-1, -1, -1):
            if i == len(nums)-1:
                suffix[i] = nums[i]
                continue
            suffix[i] = nums[i] * suffix[i+1]

        ans = []
        for i in range (len(nums)):
            if i == 0:
                ans.append(suffix[i+1])
                continue
            if i == (len(nums) - 1):
                ans.append(prefix[i-1])
                continue
            ans.append(prefix[i-1]*suffix[i+1])
            
        return ans

        
