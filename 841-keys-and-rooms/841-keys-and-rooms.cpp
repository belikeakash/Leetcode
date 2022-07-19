class Solution {
public:
    vector<int>ar[1002];
    int vis[1002];
    void DFS(int node) {
        vis[node] = 1;
        for(auto x:ar[node]) {
           if(vis[x]==0) DFS(x);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<a[i].size();j++) {
                ar[i].push_back(a[i][j]);
            }
        }
        // vis[0]=1;
        // for(int i=0;i<n;i++) {
        //     if(vis[i]==0) {
        //         DFS(i);
        //     }
        // }
        DFS(0);
        for(int i=0;i<n;i++) cout<<vis[i]<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++) if(vis[i]==0) return 0;
        return 1;
    }
};