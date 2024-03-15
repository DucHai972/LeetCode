/* Same as Hieu and Duc Hai*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> post(nums.size(), 1);
        int pos = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
               pre[i] = nums[i]; 
            } else
            pre[i] = pre[i - 1] * nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                post[i] = nums[i];
            } else{
                post[i] = post[i + 1] * nums[i];
            }
        }
        vector<int> result(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                result[i] = post[i + 1];
            } else if(i == nums.size() - 1){
                result[i] = pre[i - 1];
            } else{
                result[i] = pre[i - 1] * post[i + 1];
            }
        }
        return result;
    }
};
