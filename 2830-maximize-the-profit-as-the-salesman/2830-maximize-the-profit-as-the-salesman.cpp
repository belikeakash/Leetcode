class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        if(a[0]==b[0]) {
            if(a[2]==b[2]) return a[1]<b[1];
            return a[2]>b[2];
        }
        return a[0]<b[0];
    }
    vector<int>dp;
    int nextIdx(vector<vector<int>>&a, int x) {
        int l = 0;
        int r = a.size()-1;
        int ans = INT_MAX;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(a[mid][0]>a[x][1]) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        
        return ans;
    }
    
    
    int func(int i, vector<vector<int>>&a, int n) {
        if(i>=a.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pos = nextIdx(a, i);
        int take = a[i][2] + func(pos, a, n);
        int not_take = func(i+1, a, n);
        
        return dp[i] = max(take, not_take);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& a) {
        sort(a.begin(), a.end(), cmp);
        // for(auto x:a) {
        //     cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
        // }
        dp.resize(a.size()+1, -1);
        return func(0, a, n);
        //return 0;
    }
};