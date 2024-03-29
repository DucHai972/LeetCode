class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> check;
        for(int i = 0; i < nums.size(); i++){
            int x  = abs(nums[i]);
            if(nums[x - 1] < 0 ){
                check.push_back(x);
            }
            nums[x - 1] *= -1;
        }
    return check;
    }
};
