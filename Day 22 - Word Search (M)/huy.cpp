class Solution {
public:
    int m,n;
    bool vi[11][11];
    int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i,int j, int cur, string &word, vector<vector<char>> &board) {
        if(i < 0 || i >= m || j < 0 || j >= n) 
            return 0;
        if(vi[i][j]==1 || board[i][j] != word[cur])
            return 0;
        if(cur == word.size()-1)
            return 1;
        // cout<<i<<' '<<j<<'\n';
        vi[i][j]=1;
        return dfs(i+1,j,cur+1,word,board) ||
                dfs(i-1,j,cur+1,word,board) ||
                dfs(i,j+1,cur+1,word,board) ||
                dfs(i,j-1,cur+1,word,board) ||
                (vi[i][j] = 0);
    }
    bool exist(vector<vector<char>>& board, string word) {
        // check if there's more char in word than board
        int bcnt[256]={}, wcnt[256]={};
        for(auto x:board)
            for(auto y:x) 
                bcnt[y]++;
        for(char x:word) wcnt[x]++;
        for(int i=0;i<256;i++) 
            if(wcnt[i] > bcnt[i]) 
            return 0;

        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++)
                if(dfs(i,j,0,word,board))
                    return 1;
                else memset(vi,0,sizeof(vi));
        return 0;
    }
};