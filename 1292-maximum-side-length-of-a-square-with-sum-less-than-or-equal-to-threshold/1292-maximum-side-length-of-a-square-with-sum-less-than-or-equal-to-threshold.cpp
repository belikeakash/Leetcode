class Solution {
public:
    int maxSideLength(vector<vector<int>>& a, int t) {
        int ans = 0;
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>sum(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                sum[i][j] = a[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        cout<<ans<<endl;
        // int ans = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int x = min(i,j);
                int u=0;
                for(int k=1;k<=x;k++) {
                    u = sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k];
                    if(u<=t) {
                    ans = max(ans,k);
                }
                } 
                
            }
        }
        return ans;
    }
};