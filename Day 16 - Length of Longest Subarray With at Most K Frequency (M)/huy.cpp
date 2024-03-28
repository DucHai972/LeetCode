class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        unordered_map<int,int> m;
        int res = 0;
        int l = 0, r = 0, n = a.size();
        while(r < n) {
            if(m.find(a[r]) == m.end()) 
                m[a[r]]=0;
            m[a[r]]++;
            // not as optimized
            // while(l <= r && m[a[r]] > k)
            //     m[a[l++]]--;
            if(m[a[r]] > k)
                while(l <= r) {
                    m[a[l++]]--;
                    if(a[l-1] == a[r]) break;
                }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};