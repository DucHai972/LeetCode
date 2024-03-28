#Consistency is key 
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map <int, int> map;
        int n = nums.size();
        for(int l = 0, r = 0; r < n; r++){
            map[nums[r]]++;
            if(map[nums[r]] > k){
                while(nums[l] != nums[r]){
                    map[nums[l]]--;
                    l++;
                }
                map[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
     }
};
