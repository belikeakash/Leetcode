class Solution {
public:
    unordered_map<int,int>m1,m2;
    vector<vector<long long>>dp;
    long long func(int x,int i, int n, int m, vector<int>&a, vector<int>&b) {
        if(i>=n && x==1) return 0;
        if(i>=m && x==0) return 0;
        long long ans1=0,ans2=0;
        if(dp[i][x]!=-1) return dp[i][x];
        if(x==1) {
            if(m2.count(a[i])) {
                ans1 = a[i] + max(func(x,i+1,n,m,a,b),func(!x,m2[a[i]],n,m,a,b));
            }
            else ans1 = a[i] + func(x,i+1,n,m,a,b);
        }
        else if(x==0) {
            if(m1.count(b[i])) {
                ans2 = b[i] + max(func(x,i+1,n,m,a,b),func(!x,m1[b[i]],n,m,a,b));
            }
            else ans2 = b[i] + func(x,i+1,n,m,a,b);
        }
        return dp[i][x] = max(ans1,ans2);
    }
    int maxSum(vector<int>& a, vector<int>& b) {
        for(int i=a.size()-1;i>=0;i--) {
            m1[a[i]]=i+1;
        }
        for(int i=b.size()-1;i>=0;i--) {
            m2[b[i]]=i+1;
        }
        dp.resize(100002,vector<long long>(2,-1));
        long long ans = max(func(1,0,a.size(),b.size(),a,b),func(0,0,a.size(),b.size(),a,b))%1000000007;
        return ans;
    }
};