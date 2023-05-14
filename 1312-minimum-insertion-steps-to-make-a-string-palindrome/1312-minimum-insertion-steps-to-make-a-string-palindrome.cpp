class Solution {
public:
    vector<vector<int>>dp;
    int mininsertions(string&s, int si, int ei){
        if(dp[si][ei]!=-1)return dp[si][ei];
        if(si>=ei)return 0;
        if(s[si]==s[ei]){
            return dp[si][ei]=mininsertions(s,si+1,ei-1);
        }
        return dp[si][ei]=1+min(mininsertions(s,si+1,ei),mininsertions(s,si,ei-1));
    }
    int minInsertions(string s) {
        dp.resize(s.size()+1, vector<int>(s.size()+1,-1));
        return mininsertions(s,0,s.size()-1);
    }
};