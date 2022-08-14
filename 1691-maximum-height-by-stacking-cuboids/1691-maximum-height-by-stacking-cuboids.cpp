class Solution {
public:
    unordered_map<string,int>m;
    int dp[110][110];
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[0]<b[0];
    }
    int func(int prev, int i, int n, vector<vector<int>>&a) {
        if(i>=n) return 0;
        string s = to_string(prev+1) + "*" + to_string(i);
        if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        int ans1=0,ans2=0,ans3=0,ans4=0;
        if(prev==-1 || (a[prev][0]<=a[i][0] && a[prev][1]<=a[i][1] && a[prev][2]<=a[i][2])) {
            ans1= a[i][2] + func(i,i+1,n,a);
        }
        ans2 = func(prev,i+1,n,a);
        return dp[prev+1][i] = max({ans1,ans2});
    }
    int maxHeight(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        int n = a.size();
        for(auto &x:a) {
            sort(x.begin(),x.end());
        }
        sort(a.begin(),a.end());
        for(auto x:a) {
            cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
        }
        cout<<endl;
        return func(-1, 0,n,a);
    }
};