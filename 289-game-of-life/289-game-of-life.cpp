class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        // cout<<a[1][0]<<endl;
        for(int i=0;i<n;i++) {
            
            for(int j=0;j<m;j++) {
                int cnt = 0; 
                if(j+1<m && (a[i][j+1]==1 || a[i][j+1]==2 ))cnt++;
                if(j-1>=0 && (a[i][j-1]==1 || a[i][j-1]==2 )) cnt++;
                if(i+1<n && (a[i+1][j]==1 || a[i+1][j]==2)) cnt++;
                if(i-1>=0 && (a[i-1][j]==1 || a[i-1][j]==2))cnt++;
                if(i+1<n && j+1<m && (a[i+1][j+1]==1 || a[i+1][j+1]==2)) cnt++;
                if(i+1<n && j-1>=0 && (a[i+1][j-1]==1 || a[i+1][j-1]==2)) cnt++;
                if(i-1>=0 && j+1<m && (a[i-1][j+1]==1 || a[i-1][j+1]==2)) cnt++;
                if(i-1>=0 && j-1>=0 && (a[i-1][j-1]==1 || a[i-1][j-1]==2)) cnt++;
                
                if(cnt<2 && a[i][j]==1) a[i][j] = 2;
                if(cnt>=2 && cnt<=3 && a[i][j]==1) a[i][j] = 1;
                if(cnt>3 && a[i][j]==1) a[i][j] = 2;
                if(cnt==3 && a[i][j]==0) a[i][j] = 3;
                
                cout<<cnt<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j]==2) a[i][j] = 0;
                else if(a[i][j]==3) a[i][j] = 1;
                // cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};