class Solution {
public:
    unordered_map<string, int>dp;
    bool func(int k, int i, vector<int>&a) {
        if(k<=0) return 0;
        if(!m.count(i)) return 0;
        if(m[i]==a.size()) return 1;
        string s = to_string(i) + "+" + to_string(k);
        if(dp.count(s)) return dp[s];
        return dp[s] = func(k,i+k,a) || func(k-1, i+k-1, a) || func(k+1, i+k+1, a);
    }
    unordered_map<int, int>m;
    bool canCross(vector<int>& a) {
        int j = 1;
        for(auto x:a) {m[x]=j; j++;}
        if(a[1]!=1) return 0;
        return func(1, 1, a);
    }
};