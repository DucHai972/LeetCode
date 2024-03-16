class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        psum = ret = 0
        dic = {0:-1}
        for i in range(len(nums)):
            psum += 1 if nums[i] == 1 else -1
            if psum in dic:
                ret = max(ret, i - dic[psum])
            else:
                dic[psum] = i
        return ret
