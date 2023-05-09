class Solution {
public:
    vector<int>dp;
    int func(int i, string s, unordered_map<string,int>m) {
        if(i==s.size()) {
            return 1;
        }
        string u = "";
        if(dp[i]!=-1) return dp[i];
        bool ans = 0;
        for(int j=i;j<s.size();j++) {
            u+=s[j];
            if(m[u]) {
                ans = ans || func(j+1,s,m);
            }
        }
        
        return dp[i]= ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>m;
        dp.resize(s.size()+1,-1);
        for(auto x:wordDict) {
            m[x]=1;
        }
        return func(0,s,m);
    }
};