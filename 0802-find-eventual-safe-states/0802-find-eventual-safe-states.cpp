class Solution {
public:
    unordered_map<int, int>m;
    bool DFS(int node, vector<vector<int>>&ar, vector<int>&vis, vector<int>&flag) {
        vis[node] = 1;
        int ans = 1;
        for(auto x:ar[node]) {
            if(!vis[x]) {
                bool u = DFS(x, ar, vis, flag);
                ans = ans & u;
            }
            else {
                ans = ans & flag[x];
            }
        }
        flag[node] = ans;
        
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& ar) {
        int n = ar.size();
        for(int i=0;i<n;i++) {
            if(ar[i].size()==0) m[i] = 1;
        }
        vector<int>flag(n, 0), vis(n,0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                DFS(i, ar, vis, flag);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++) {
            if(flag[i]) ans.push_back(i);
        }
        
        return ans;
    }
    
};