#**Method 1**

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

#**Method 2** 
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        cnt = nums.count(0)
        n = len(nums)
        prefix = [1] * (n + 1)
        suffix = [1] * (n + 1)
        for i in range(1, n+1):
            prefix[i] = prefix[i-1] * nums[i-1]
            suffix[i] = suffix[i-1] * nums[n-i]
        ret = [0] * n
        for i in range(1, n+1):
            print(i,prefix[i-1], suffix[n-i])
            ret[i-1] = prefix[i-1] * suffix[n-i]
        print(prefix)
        print(suffix)
        return ret 
