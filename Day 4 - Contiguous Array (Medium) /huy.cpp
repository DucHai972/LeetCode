// can use array instead of map to improve run time (but may increase mem)
class Solution {
public:

    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int s=0,res=0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) s++;
            else s--;
            if(m.find(s)!=m.end())
                res=max(res,i-m[s]);
            else 
                m[s]=i;
        }
        return res;
    }
};
