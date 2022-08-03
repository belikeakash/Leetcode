class Solution {
public:
    vector<int>dp;
    int func(int x, vector<int>&a) {
        if(x>=a.size()-1) return 0;
        if(dp[x]!=-1) return dp[x];
        int ans = 100007;
        for(int i=x+1;i<=x+a[x];i++) {
            ans = min(ans,1+func(i,a));
        }
        return dp[x] = ans;
    }
    int jump(vector<int>& a) {
    //     if(a.size()==1) return 0;
        int n = a.size();
        dp.resize(a.size()+1,100009);
        dp[0] = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<=i+a[i] && j<n;j++) {
                dp[j] = min(dp[j],dp[i]+1);
            }
        }
        return dp[n-1];
        // return func(0,a);
    }
};