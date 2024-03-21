// <impl>
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& newIt) {
        //more clean and beautiful way:
        int i=0;
        int n = it.size();
        vector<vector<int> > res;
        while(i < n && it[i][1] < newIt[0])
            res.push_back(it[i++]);
        while(i < n && it[i][0] <= newIt[1]) // newIt[0] <= it[i][1]
            newIt[0] = min(newIt[0],it[i][0]),
            newIt[1] = max(newIt[1],it[i][1]),
            i++;
        res.push_back(newIt);
        while(i < n)
            res.push_back(it[i++]);
        return res;
        // old way:
        
        // bool ov[10007] = {0};
        // int n = it.size();
        // int start = newIt[0],
        //     end = newIt[1];
        // for(int i=0;i<n;i++) {
        //     if(it[i][0] <= start && start <= it[i][1]) ov[i]=1;
        //     if(it[i][0] <= end && end <= it[i][1]) ov[i]=1;
        //     if(start <= it[i][0] && it[i][1] <= end) ov[i]=1;
        // }
        // int ms = -1, me = -1;
        // for(int i=0;i<n;i++) 
        //     if(ov[i]) {
        //         ms = i;
        //         break;
        //     }
        // for(int i=n-1;i>=0;i--) 
        //     if(ov[i]) {
        //         me = i;
        //         break;
        //     }
        
        // vector<vector<int> > res;
        // for(int i=0;i<ms;i++)
        //     res.push_back(it[i]);
        
        // int newS = start;
        // if(ms != -1) newS=min(newS,it[ms][0]);
        // int newE = end;
        // if(me != -1) newE=max(newE,it[me][1]);
        // cout<<ms<<' '<<me<<'\n';
        // vector<int> x = {newS,newE};
        // if(me==-1 && ms==-1) {
        //     me=0;
        //     while(me < n && it[me][0] <= newS)
        //         res.push_back(it[me++]);
        //     me--;
        // }
        // res.push_back(x);
        // for(int i=me+1;i<n;i++)
        //     res.push_back(it[i]);
        // return res;

    }
};