class Solution {
public:
    string clean(string s) {
        string res="";
        s+=' ';
        int i=0;
        while(i+1 < s.size()) 
            if((s[i]-'a' == s[i+1]-'A') || (s[i]-'A' == s[i+1]-'a'))
                i+=2;
            else res+=s[i++];
        return res;
    }
    string makeGood(string s) {
        string res=clean(s);
        while(res.size() < s.size()) 
            s = res,
            res=clean(s);
        return res;
    }
};