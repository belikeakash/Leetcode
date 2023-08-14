class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<int>>q;
        int n = a.size();
        for(int i=0;i<n;i++) {
            if(q.size()<k) q.push(a[i]);
            else {
                //cout<<q.top()<<" ";
                if(a[i]>q.top()) {q.pop(); q.push(a[i]);}
            }
        }
        
        return q.top();
    }
};