class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int j, vector<int>&a) {
        
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<=j;k++) {
            // cout<<i<<" "<<j<<endl;
            int cost = a[j+1]-a[i-1] + func(i,k-1,a) + func(k+1,j,a);
            ans = min(ans,cost);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& a) {
        a.push_back(0);
        a.push_back(n);
        sort(a.begin(),a.end());
        dp.resize(a.size()+1,vector<int>(a.size()+1,-1));
        return func(1,a.size()-2,a);
    }
};