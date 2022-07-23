class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int g=0;g<n;g++) {
            for(int i=0,j=g;j<n;i++,j++) {
                if(g==0) {
                    dp[i][j]=1;
                }
                else if(g==1) {
                    if(s[i]==s[j]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]==1) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
            }
        }
        int l=0,r=0,ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(dp[i][j]==1) {
                    ans++;
                }
            }
        }
       return ans;
    }
};