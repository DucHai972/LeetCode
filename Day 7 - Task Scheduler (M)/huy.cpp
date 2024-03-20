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
    // 2nd Method
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for(char x:tasks) 
            cnt[x-'A']++;
        sort(cnt,cnt+26,greater<int>());
        int m = cnt[0] - 1;
        int idle = m*n; // maximum need for idle state
        for(int i=1;i<26;i++)
            idle-=min(m,cnt[i]);
        
        return tasks.size() + max(idle,0);
    }
};