class Solution {
public:
    vector<int>dx = {-1,1,0,0,-1,-1,1,1};
    vector<int>dy = {0,0,-1,1,-1,1,-1,1};
    bool isValid(int x, int y, int n, int m) {
        if(x>=0 && x<n && y>=0 && y<m) return 1;
        return 0;
    }
    void func(vector<vector<char>>& v, int x, int y, int n, int m, vector<vector<int>>& vis) {
        if(!isValid(x,y,n,m)) return;
        // cout<<"a";
        vis[x][y] = 1;
        if(v[x][y]=='M'){v[x][y]='X'; return ;} 
        int ans = 0;
        for(int i=0;i<8;i++) {
            if(isValid(x+dx[i],y+dy[i],n,m)) {
                if(v[x+dx[i]][y+dy[i]]=='M') ans++;
            }
        }
        cout<<ans<<" ";
        if(ans==0) {
            v[x][y] = 'B';
            for(int i=0;i<8;i++) {
                if(isValid(x+dx[i],y+dy[i],n,m) && vis[x+dx[i]][y+dy[i]]==0) {
                    func(v,x+dx[i],y+dy[i],n,m,vis);
                }
            }
        }
        else v[x][y] = char(ans + '0');
        return;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& a, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        func(a,x,y,n,m,vis);
        
        return a;
    }
};