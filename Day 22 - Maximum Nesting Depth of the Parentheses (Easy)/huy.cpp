class Solution {
public:
    int maxDepth(string s) {
        int res = 0, d = 0;
        for(char &c:s)
            if(c=='(') d++,res=max(res,d);
            else if(c==')') d--;
        return max(res,d);
    }
};