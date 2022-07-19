class Solution {
public:
    bool DFS(int node, vector<int>&vis, vector<vector<int>>&ar){
        
        if(vis[node] == 1) return 1;
        if(vis[node]==0) {
            vis[node] = 1;
            for(auto x:ar[node]) {
                if(DFS(x,vis,ar)) return 1;
            }
        }
        vis[node] = 2;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>>ar(n);
        for(auto x:a) {
            ar[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        bool ans = 1;
        for(int i=0;i<n;i++) {
            if(DFS(i,vis,ar)) return 0;
        }
        return 1;
    }
};