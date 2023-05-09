class Solution {
public:
    bool isValid(int x, int y,vector<string>&v) {
        int n = v.size();
        for(int i=0;i<n;i++) {
            if(v[x][i]=='Q') return 0;
        }
        for(int i=0;i<n;i++) {
            if(v[i][y]=='Q') return 0;
        }
        int i = x; int j = y;
        x = i,y=j;
        
        
        while(x-1>=0 && y-1>=0) {
            if(v[x-1][y-1]=='Q') return 0;
            x--;
            y--;
        }
        x = i;
        y = j;
        while(x-1>=0 && y+1<n) {
            if(v[x-1][y+1]=='Q') return 0;
            x--;
            y++;
        }
        x = i;
        y = j;
        while(x+1<n && y-1>=0) {
            if(v[x+1][y-1]=='Q') return 0;
            x++;
            y--;
        }
        x = i;
        y = j;
        while(x+1<n && y+1<n) {
            if(v[x+1][y+1]=='Q') return 0;
            x++;
            y++;
        }
        return 1;
    }
    int func(int x,int n, vector<vector<string>>&v, vector<string>&a) {
        //cout<<x<<" ";
        if(x>=n) {v.push_back(a); return 0;}
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(isValid(x,i,a)) {
                a[x][i] = 'Q';
                ans = ans || func(x+1,n,v,a);
                a[x][i] = '.';
            }
        }
        
        return ans;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string u = "";
        vector<string>a;
        for(int i=0;i<n;i++) {
            u+='.';
        }
        for(int i=0;i<n;i++) {
            a.push_back(u);
        }
        func(0,n,ans,a);
        return ans; 
    }
};