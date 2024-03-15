class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if nums.count(0) == len(nums):
            return [0] * len(nums)
        hehe = 1
        cnt = 0
        for x in nums:
            if x != 0:
                hehe *= x
            else:
                cnt += 1
        ret = []
        for x in nums:
            if x != 0:
                if cnt > 0:
                    ret.append(0)
                    # cnt -= 1
                else:
                    ret.append(int(hehe/x))
            else:
                if cnt > 1:
                    ret.append(0)
                else:
                    ret.append(hehe)
        return ret
