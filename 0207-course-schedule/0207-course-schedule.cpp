class Solution {
public:
    bool DFS(int node, vector<int> ar[], vector<int>&vis, vector<int>&pvis) {
        vis[node] = 1;
        pvis[node] = 1;
        for(auto x:ar[node]) {
            if(vis[x]==0) {
                if(DFS(x,ar,vis,pvis)==true) return 1;
            }
            else if(vis[x]==1) {
                if(pvis[x]==1) return 1;
            }
        }
        pvis[node] = 0;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int>ar[n];
        vector<int>vis(n,0);
        vector<int>pvis(n,0);
        for(auto x:a) {
            ar[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++) {
            if(vis[i]==0) {
                if(DFS(i,ar,vis,pvis)==true) {
                    return false;
                }
            }
        }
        return true;
    }
};