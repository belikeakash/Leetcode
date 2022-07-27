class Solution {
public:
    vector<int>dp;
    int func(int pre, int cur, vector<int>&a, int f) {
        if(cur>f) {
            return 0;
        }
        if(dp[cur]!=-1) return dp[cur];
        int ans = 0;
        if(cur-pre>1) {
            ans = max(a[cur] + func(cur,cur+2,a,f),func(pre,cur+1,a,f));
        }
        cout<<ans<<" ";
        return dp[cur] = ans;
    }
    int rob(vector<int>& a) {
        if(a.size()==1) return a[0];
        dp.resize(a.size()+1,-1);
        int ans1 =  func(-2,0,a,a.size()-2);
        // dp.resize(a.size()+1,-1);
        for(int i=0;i<a.size()+1;i++) dp[i]=-1;
        int ans2 = func(-1,1,a,a.size()-1);
        // cout<<ans1<<" "<<ans2<<endl;
        return max(ans1,ans2);
    }
};