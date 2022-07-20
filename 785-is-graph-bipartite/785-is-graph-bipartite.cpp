class Solution {
public:
    bool DFS(int node, vector<vector<int>>& a, int c, vector<int>&vis,vector<int>&col) {
        vis[node] = 1;
        col[node] = c;
        bool ans = 1;
        for(auto x:a[node]) {
            if(vis[x]==0) {
                if(DFS(x,a,!c,vis,col)==0) return 0;
            }
            else {
                if(col[x]==col[node]) return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& a) {
        int c = 1;
        vector<int>vis(a.size(),0);
        vector<int>col(a.size(),-1);
        int n = a.size();
        for(int i=0;i<n;i++) {
            if(vis[i]==0) {
                if(DFS(i,a,0,vis,col)==0) return 0;
            }
        }
        return 1;
    }
};