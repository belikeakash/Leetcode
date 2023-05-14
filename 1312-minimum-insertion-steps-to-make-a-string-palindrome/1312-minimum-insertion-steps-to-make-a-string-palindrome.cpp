class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int j, string s) {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] =  func(i+1,j-1,s);
        return dp[i][j] =  1 + min(func(i+1,j,s), func(i,j-1,s));
    }
    int minInsertions(string s) {
        dp.resize(s.size()+1, vector<int>(s.size()+1, 0));
        //return func(0,s.size()-1,s);
        int n = s.size();
        for(int i=n-2;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};