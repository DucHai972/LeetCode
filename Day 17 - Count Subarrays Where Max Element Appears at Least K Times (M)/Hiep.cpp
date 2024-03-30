class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int count = 0;
        long long int right = 0;
        long long int left = 0;
        long long int ans = 0;
        long long int max = *max_element(nums.begin(), nums.end());
        long long int n = nums.size();
       while(right < n){
            if(nums[right] == max){
                count++;
            }
            while(count >= k){
                if(nums[left] == max)count--;
                left++;
                ans += nums.size() - right;
            }
            right++;
        }
        return ans;
    }
};
