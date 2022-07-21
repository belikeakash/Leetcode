class Solution {
public:
    set<pair<int,int>>s;
    int ans = 0;
    void DFS(int node, vector<vector<int>>&ar, vector<int>&vis) {
        vis[node] = 1;
        for(auto x:ar[node]) {
            if(vis[x]==0) {
                if(s.count({node,x})>0) ans++;
                DFS(x,ar,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& a) {
        vector<vector<int>>ar(n);
        for(int i=0;i<a.size();i++) {
            int x = a[i][0];
            int y = a[i][1];
            ar[x].push_back(y);
            ar[y].push_back(x);
            s.insert({x,y});
        }
        vector<int>vis(n,0);
        DFS(0,ar,vis);
        return ans;
    }
};