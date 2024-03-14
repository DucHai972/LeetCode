class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        p_sum = {0:1}
        cur_sum = 0
        ret = 0
        for x in nums:
            cur_sum += x
            if goal <= cur_sum:
                ret += p_sum.get(cur_sum - goal,0)
            if cur_sum not in p_sum:
                p_sum[cur_sum] = 1
            else:
                p_sum[cur_sum] += 1
        
        return ret
