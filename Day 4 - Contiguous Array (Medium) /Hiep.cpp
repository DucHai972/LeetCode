class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_subArray = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                sum += 1;
            }else sum -= 1;
            if(sum == 0){
                max_subArray = i + 1;
            } else if(mp.find(sum) != mp.end()){
                max_subArray = max(max_subArray, i - mp[sum]);
            } else{
                mp[sum] = i;
            }
        }
         return max_subArray;
        }
};
