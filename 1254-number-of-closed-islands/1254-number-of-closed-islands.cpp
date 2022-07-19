class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>& a, vector<vector<int>>& vis) {
        if(vis[i][j]==1 || a[i][j]==1) return 0;
        return 1;
    }
    int DFS(int x, int y, vector<vector<int>>& a, vector<vector<int>>& vis) {
        if(!(isValid(x,y,a,vis))) return 1;
        if((x==0 || x==a.size()-1 || y==0 || y==a[0].size()-1)) return 0;
        
        vis[x][y] = 1;
        
        bool p = DFS(x+1,y,a,vis);
        bool q = DFS(x-1,y,a,vis);
        bool r = DFS(x,y+1,a,vis);
        bool s = DFS(x,y-1,a,vis);
        return p and q and r and s;
    }
    int closedIsland(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int cnt = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]==0 && a[i][j]==0) {
                    if(DFS(i,j,a,vis)) {cout<<i<<" "<<j<<endl; cnt++;}
                }
            }
        }
        return cnt;
    }
};