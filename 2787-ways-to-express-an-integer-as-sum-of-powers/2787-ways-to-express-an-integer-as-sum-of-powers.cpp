class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<string, int>m;
    vector<vector<int>>dp;
    int func(int i, int left, int x) {
        
        if(left==0) { return 1;}
        if(left<0 || pow(i,x)>left) return 0;
        string s = to_string(i) + "+" + to_string(left);
        if(dp[i][left]!=-1) return dp[i][left];
        // if(m.count(s)) return m[s];
        int ans = 0;
        //cout<<i<<" "<<left<<endl;
//         for(int j=i;j<=left;j++) {
//             ans+=func(x+1, n, left-pow(j,i), x);
//         }
        
        ans=(func(i+1,left-pow(i,x),x))%mod;
         
        ans= (ans+func(i+1, left, x))%mod;
        return dp[i][left] = ans;
    }
    int numberOfWays(int n, int x) {
        dp.resize(n+1, vector<int>(n+1,-1));
        return func(1,n,x);
    }
};