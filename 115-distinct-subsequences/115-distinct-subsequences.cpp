class Solution {
public:
    
//     int func(int n1, int n2, string s1, string s2) {
        
//         if(n2<0) return 1;
//         if(n1<0) return 0;
//         if(dp[n1][n2]!=-1) return dp[n1][n2];
//         if(s1[n1]==s2[n2]) {
//             return dp[n1][n2] = func(n1-1,n2-1,s1,s2) + func(n1-1,n2,s1,s2);
//         }
//         else return dp[n1][n2] = func(n1-1,n2,s1,s2);
//     }
    int numDistinct(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<double>>dp(n1+1,vector<double>(n2+1,0));
        for(int i=0;i<=n1;i++) dp[i][0] = 1;
        for(int i=1;i<=n1;i++) {
            for(int j=1;j<=n2;j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n1][n2];
    }
};