class Solution:
    def pivotInteger(self, n: int) -> int:
        if n == 1:
            return 1
        sum = n*(n+1)/2
        for i in range (int(n/2), n):
            temp = (i-1)*i/2
            if (i*(i+1)/2 == sum - temp):
                return i
        return -1

        
