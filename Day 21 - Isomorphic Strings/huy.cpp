// <string>
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        bool md[256] = {};
        if(s.size() != t.size()) return 0;
        for(int i=0;i<s.size();i++)
            if(m.find(s[i]) == m.end()){
                if(md[t[i]]) return 0;
                m[s[i]] = t[i];
                md[t[i]] = 1;
            } else if(m[s[i]] != t[i]) return 0;
                    
        return 1;
    }
};