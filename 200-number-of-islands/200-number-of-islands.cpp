class Solution {
public:
    void DFS(int i,int j,vector<vector<char>>& a,vector<vector<int>>& vis,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || a[i][j]=='0') return;
        vis[i][j] = 1;
        DFS(i+1,j,a,vis,n,m);
        DFS(i-1,j,a,vis,n,m);
        DFS(i,j+1,a,vis,n,m);
        DFS(i,j-1,a,vis,n,m);
    }
    int numIslands(vector<vector<char>>& a) {
        vector<vector<int>>vis(a.size(),vector<int>(a[0].size(),0));
        int cnt = 0;
        for(int i=0;i<a.size();i++) {
            for(int j=0;j<a[i].size();j++) {
                if(a[i][j]=='1' && vis[i][j]==0) {
                    cout<<"a";
                    cnt++;
                    DFS(i,j,a,vis,a.size(),a[i].size());
                }
            }
        }
        return cnt;
    }
};