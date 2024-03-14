class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int sums = 0;
        unordered_map<int,int> prefixed_sums;
        prefixed_sums[0] = 1; 
        for(int i = 0; i < nums.size(); i++){
            sums += nums[i];
            if(prefixed_sums.find(sums - goal) != prefixed_sums.end()){
                count += prefixed_sums[sums - goal];
            }
            prefixed_sums[sums]++;
        }
        return count;
    }
};
