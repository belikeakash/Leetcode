class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        priority_queue<int>q;
        int n = a.size();
        for(auto x:a) q.push(x);
        while(q.size()>1) {
            int p1 = q.top();
            q.pop();
            int p2 = q.top();
            q.pop();
            if(p1!=p2) {
                q.push(p1-p2);
            }
        }
        if(q.size()==0) return 0;
        else return q.top();
    }
};