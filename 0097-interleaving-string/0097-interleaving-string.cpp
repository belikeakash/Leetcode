class Solution {
public:
    int dp[105][105][205];
    bool func(int i, int j, int k, string s1, string s2, string s3) {
        if(i>=s1.size() && j>=s2.size() && k>=s3.size()) return 1;
        int ans1 = 0;
        int ans2 = 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(i<s1.size() && s1[i]==s3[k]) {
            ans1 = func(i+1, j, k+1, s1, s2, s3);
        }
        if(j<s2.size() && s2[j]==s3[k]) {
            ans2 = func(i, j+1, k+1, s1, s2, s3);
        }
        
        return dp[i][j][k] = ans1 || ans2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1+n2!=n3) return 0;
        memset(dp, -1, sizeof(dp));
        return func(0,0,0,s1,s2,s3);
    }
};