class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int MAX = 101;
        int res=0;
        while(t[k]!=0) {
            for(int i=0;i<t.size() && t[k]!=0;i++)
                if(t[i])
                    t[i]--,
                    res++;
        }
        return res;
    }
};