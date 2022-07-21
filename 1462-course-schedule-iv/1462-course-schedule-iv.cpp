class Solution {
public:
    vector<vector<int>>dp;
    bool DFS(vector<vector<int>>&ar, int node, int temp, vector<int>&vis) {
        if(dp[node][temp]!=-1) return dp[node][temp];
        if(node==temp) return 1;
        vis[node] = 1;
        for(auto x:ar[node]) {
            if(vis[x]==0) {
                if(DFS(ar,x,temp,vis)) return dp[x][temp] = 1;
            }
        }
        return dp[node][temp] = 0;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& v, vector<vector<int>>& q) {
        vector<int>vis(n,0);
        vector<vector<int>>ar(n);
        for(int i=0;i<v.size();i++) {
            int x = v[i][0];
            int y = v[i][1];
            ar[x].push_back(y);
        }
        vector<bool>ans;
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<q.size();i++) {
            for(int i=0;i<n;i++) vis[i] = 0;
            int x = q[i][0];
            int y = q[i][1];
            if(DFS(ar,x,y,vis)) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};