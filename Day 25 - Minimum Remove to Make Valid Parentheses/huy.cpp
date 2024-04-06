class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
            if(s[i]=='(' || s[i]==')') {
                if(s[i]=='(') 
                    st.push(i);
                else if(st.size()) 
                        st.pop();
                    else s[i] = '-';
            }
        while(st.size()) 
            s[st.top()] = '-',
            st.pop();
        string res="";
        for(char &c:s) 
            if(c!='-') res+=c;
        return res;
    }
};