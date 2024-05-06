class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int &x:students)
            q.push(x);
        for(int i=0;i<sandwiches.size();i++){
            int d=0;
            while(d <= q.size())
                if(q.front() == sandwiches[i]) {
                    q.pop();
                    break;
                }
                else {
                    d++;
                    q.push(q.front());
                    q.pop();
                }
            if(d > q.size()) 
                break;
        }
        return q.size();
    }
};