class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int j, vector<int>&a) {
        
        if(i+1==j) return 0;
        else if(dp[i][j]!=-1) return dp[i][j];
        else {
           int ans = INT_MAX;
        for(int k=i+1;k<j;k++) {
            // cout<<i<<" "<<j<<endl;
            int cost = a[j]-a[i] + func(i,k,a) + func(k,j,a);
            ans = min(ans,cost);
        }
        return dp[i][j] = ans; 
        }
        
    }
    int minCost(int n, vector<int>& a) {
        a.push_back(0);
        a.push_back(n);
        sort(a.begin(),a.end());
        dp.resize(102,vector<int>(102,-1));
        return func(0,a.size()-1,a);
    }
};