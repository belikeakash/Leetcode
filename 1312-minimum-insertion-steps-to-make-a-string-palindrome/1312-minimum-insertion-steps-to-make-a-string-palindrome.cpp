class Solution {
public:
    int dp[510][510];
    int mininsertions(string&s, int si, int ei){
        if(dp[si][ei]!=-1)return dp[si][ei];
        if(si>=ei)return 0;
        if(s[si]==s[ei]){
            return dp[si][ei]=mininsertions(s,si+1,ei-1);
        }
        return dp[si][ei]=1+min(mininsertions(s,si+1,ei),mininsertions(s,si,ei-1));
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return mininsertions(s,0,s.size()-1);
    }
};