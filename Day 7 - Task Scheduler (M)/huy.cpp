class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for(char x:tasks) 
            cnt[x-'A']++;
        int m = 0;
        int mc = 0;
        for(int i=0;i<26;i++)
            if(cnt[i] > m) 
                m=cnt[i],
                mc=1;
            else if (cnt[i]==m) mc++;
        
        return max(int(tasks.size()), (m-1)*(n+1) + mc);
    }
};