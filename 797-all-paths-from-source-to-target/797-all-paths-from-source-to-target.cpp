class Solution {
public:
    vector<vector<int>>ar;
    vector<vector<int>>ans;
    vector<int>vis;
    vector<int>v;
    void func(int node, int des) {
        // vis[node]=1;
        
        if(node==des) {
            ans.push_back(v);
            return;
        }
        for(auto x:ar[node]) {
            if(vis[x]==0) {
                v.push_back(x);
                func(x,des);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();
        ar.resize(n);
        for(int i=0;i<n;i++) {
            for(auto x:g[i]) ar[i].push_back(x);
        }
        vis.resize(n,0);
        v.push_back(0);
        func(0,n-1);
        return ans;
    }
};