class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int p = 1;
        int l=0,r=0;
        while(r < nums.size()) {
            p*=nums[r];
            while(p >= k && l <= r) 
                p/=nums[l++];
            res+=r-l+1;
            // cout<<l<<' '<<r<<'\n';
            r++;
        }
        return res; 
    }
};