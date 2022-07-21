class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<int>in(n,0);
        vector<vector<int>>v(n);
        for(int i=0;i<a.size();i++) {
            int x = a[i][0]; int y = a[i][1];
            // cout<<x<<" "<<y<<"  "; 
            v[y].push_back(x);
        }
        for(auto x:a) {
            in[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++) {
            if(in[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()) {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto x:v[curr]) {
                in[x]--;
                if(in[x]==0) q.push(x);
            }
        }
        for(auto x:ans) cout<<x<<" ";
        if(ans.size()==n) return ans;
        vector<int>p;
        return p;
    }
};