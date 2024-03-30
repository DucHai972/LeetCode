class Solution {
public:
    void ins(unordered_map<int,int> &m, int &dif, int x){
        if(m.find(x) == m.end()) {
            dif++;
            m[x]=0;
        }
        m[x]++;
    }
    void del(unordered_map<int,int> &m, int &dif, int x){
        m[x]--;
        if(m[x] == 0) {
            m.erase(x);
            dif--;
        }
    }
    int subWithAtMostK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int l=0,r=0,n=nums.size();
        int res = 0, dif = 0;
        while(r < n) {
            ins(m,dif,nums[r]);
            while(l <= r && dif > k) {
                del(m,dif,nums[l]);
                l++;
            }
            res+=r-l+1;
            r++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subWithAtMostK(nums,k) - subWithAtMostK(nums,k-1);
    }
};