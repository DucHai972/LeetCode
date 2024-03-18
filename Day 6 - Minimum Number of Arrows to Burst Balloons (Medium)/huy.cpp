class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        // for(auto x:p) 
        //     cout<<x[0]<<' '<<x[1]<<'\n';
        int i =0,res = 0;
        while(i < p.size()) {
            int r = p[i][1];
            res++;
            // cout<<i<<' '<<r<<'\n';
            while(i < p.size() && p[i][0] <= r)
                r = min(r,p[i][1]),
                i++;
        }
        return res;
    }
};