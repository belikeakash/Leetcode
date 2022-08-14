class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<n;i++) {
            bool flag = 0;
            for(int j=0;j<m;j++) {
                if(flag) {
                    if(a[i][j]==1) a[i][j]=0;
                    else a[i][j] = 1;
                }
                else if(a[i][j]==0 && j==0) {
                    a[i][j] = 1;
                    flag = 1;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<m;i++) {
            int cnt = 0;
            for(int j=0;j<n;j++) {
                if(a[j][i]==0) cnt++;
            }
            // cout<<cnt<<"*"<<endl;
            if(cnt>n/2) {
                for(int j=0;j<n;j++) {
                    if(a[j][i]==0) a[j][i] = 1;
                    else a[j][i]=0;
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            int ans = 0;
            for(int j=0;j<m;j++) {
                if(a[i][j]==1) {
                    ans+= pow(2,m-1-j);
                }
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
            res+=ans;
        }
        return res;
    }
};