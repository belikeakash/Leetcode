class Solution {
public:
    vector<vector<int>>dp;
    int func(int pre, int cur, vector<int>&a) {
        if(cur==a.size()) return 0;
        if(dp[pre+1][cur+1]!=-1) return dp[pre+1][cur+1];
        if(pre==-1 || a[cur]>a[pre]) {
            return dp[pre+1][cur+1] = max(1 + func(cur,cur+1,a), func(pre,cur+1,a)) ;
        }
        else {
            return dp[pre+1][cur] = func(pre,cur+1,a);
        }
    }
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        dp.resize(a.size()+1,vector<int>(a.size()+1,0));
        // return func(-1,0,a);
        for(int i=n-1;i>=0;i--) {
            for(int j=i-1;j>=-1;j--) {
                if(j==-1 || a[i]>a[j]) {
                    dp[i][j+1] = max(1+dp[i+1][i+1],dp[i+1][j+1]);
                }
                else {
                    dp[i][j+1] = dp[i+1][j+1];
                }
            }
        }
        // for(int i=0;i<=n;i++) {
        //     for(int j=0;j<=n;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
    }
};