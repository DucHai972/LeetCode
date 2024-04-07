class Solution {
public:
    int f[101][101];
    bool check(int l,int r,string &s) {
        if(l > r) return 1;
        if(l==r) 
            return s[l]=='*';
        if(f[l][r] != -1) return f[l][r];
        f[l][r]=0;
        if((s[l]=='(' && (s[r]==')' || s[r]=='*'))
             || ((s[l]=='(' || s[l]=='*')  && s[r]==')')
             || (s[l]=='*' && s[r]=='*')) 
            f[l][r] = check(l+1,r-1,s);
        for(int i=l;i<=r && f[l][r]==0;i++) {
            f[l][r] = f[l][r] || (check(l,i,s) && check(i+1,r,s));
        }
        return f[l][r];
    }
    bool checkValidString(string s) {
        for(int i=0;i<s.size();i++)
            for(int j=0;j<s.size();j++) f[i][j]=-1;
        
        return check(0,s.size()-1,s);
    }
};