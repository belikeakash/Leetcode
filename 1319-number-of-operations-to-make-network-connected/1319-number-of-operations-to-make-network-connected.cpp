class Solution {
public:
    vector<int>ar[100006];
    int vis[100006];
    void DFS(int node) {
        vis[node] = 1;
        for(int x:ar[node]) {
            if(vis[x]==0) DFS(x);
        }
    }
    int makeConnected(int n, vector<vector<int>>& a) {
        int p = a.size();
        for(int i=0;i<p;i++) {
            ar[a[i][0]].push_back(a[i][1]);
            ar[a[i][1]].push_back(a[i][0]);
        }
        int cc = 0;
        for(int i=0;i<n;i++) {
            if(vis[i]==0) {
                DFS(i);
                cc++;
            }
        }
        if(cc==1) return 0;
        if(n-1>p) return -1;
        return cc-1;
    }
};