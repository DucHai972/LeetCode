class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        ans = 0
        sum_ = 0
        count = {0: 1} 

        for num in nums:
            sum_ += num
            complement = sum_ - goal
            if complement in count:
                ans += count[complement]
            
            if sum_ not in count:
                count[sum_] = 0
            count[sum_] += 1
        return ans
