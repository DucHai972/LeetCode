// Important observation:
// The number missing must in range [1,n]
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int &x:nums) 
            if(x <= 0 || n < x) x = n+1;
        for(int &x:nums) 
            if(0 <= abs(x)-1 && abs(x)-1 < n)
                nums[abs(x)-1] = -abs(nums[abs(x)-1]);
        for(int &x:nums) 
            cout<<x<<' ';
        for(int i = 0;i<n;i++)
            if(nums[i] > 0) return i+1;
        return n+1;
    }
};