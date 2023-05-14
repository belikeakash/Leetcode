class Solution {
public:
    
    int func(int i, int j, string &s, vector<vector<int>>&dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=j) return 0;
       
        if(s[i]==s[j]) return dp[i][j] =  func(i+1,j-1,s, dp);
        else return dp[i][j] =  1 + min(func(i+1,j,s,dp), func(i,j-1,s,dp));
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size()+3, vector<int>(s.size()+3, -1));
        return func(0,s.size()-1,s, dp);
    }
};