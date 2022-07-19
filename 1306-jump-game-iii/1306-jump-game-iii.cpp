class Solution {
public:
    vector<int>ar[100005];
    int vis[100005];
    void DFS(int node) {
        vis[node] = 1;
        for(auto x:ar[node]) {
            if(vis[x]==0) DFS(x);
        }
    }
    bool canReach(vector<int>& a, int x) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            if(i-a[i]>=0) ar[i].push_back(i-a[i]);
            ar[i].push_back(i+a[i]);
        }
        DFS(x);
        for(int i=0;i<n;i++) {
            if(a[i]==0 && vis[i]==1) return 1;
        }
        return 0;
    }
};