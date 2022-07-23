class Solution {
public:
//     int func(int i1, int i2, string s1, string s2, vector<vector<int>>&dp) {
//         if(i1==s1.size() || i2==s2.size()) {
//             return 0;
//         }
//         if(dp[i1][i2]!=-1) {cout<<"a"; return dp[i1][i2];}
//         if(s1[i1]==s2[i2]) return dp[i1][i2] = 1+(func(i1+1,i2+1,s1,s2,dp));
//         else return dp[i1][i2] = max(func(i1+1,i2,s1,s2,dp),func(i1,i2+1,s1,s2,dp));
        
        
//     }
    int longestPalindromeSubseq(string s) {
        string t=s;
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        reverse(t.begin(),t.end());
        int n = s.size();
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<n+1;j++) {
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};