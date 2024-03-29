class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(),nums.end());
        // vector with index of every elements equal to m
        vector<int> v;
        v.push_back(-1);
        for(int i=0;i<nums.size();i++)
            if(nums[i]==m) v.push_back(i);
        v.push_back(nums.size());
        // for each v[i], v[j] = min index for subarray [i..j] have >= k m
        // each i, res = left*right
        // where left = v[i] - v[i-1]
        // right = (v[j+1] - v[j]) + (v[j+2] - v[j]) ... = v[n] - v[j]
        long long res = 0;
        for(int i = 1;i+k < v.size();i++) {
            int j = i+k-1;
            res+=1LL*(v[i]-v[i-1])*(v.back()-v[j]);
        }
        return res;
    }
};