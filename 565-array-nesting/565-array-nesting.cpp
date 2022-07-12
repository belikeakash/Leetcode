class Solution {
public:
    vector<int>ar[100005];
    int x = 1;
    int vis[100005];
    void DFS(int node) {
        vis[node] = 1;
        for(auto y:ar[node]) {
            if(vis[y]==0) {
                
                x++;
                DFS(y);        
            }
        }
    }
    int arrayNesting(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            ar[i].push_back(a[i]);
        }
        // for(int i=0;i<n;i++) {
        //     for(auto x:ar[i]) {
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        for(int i=0;i<n;i++) {
            x = 1;
            if(vis[a[i]]==0) {
                DFS(a[i]);
                cout<<x<<" ";
                ans = max(ans,x);
            }
        }
        return ans;
    }
};