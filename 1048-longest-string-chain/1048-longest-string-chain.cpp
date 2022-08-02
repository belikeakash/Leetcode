class Solution {
public:
    int comp(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1!=n2+1) return 0;
        int i = 0;
        int j = 0;
        while(i<n1) {
            if(s1[i]==s2[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if(i==n1 && j==n2) return 1;
        else return 0;
    }
    static bool compa(string &s, string &t) {
        return s.size()<t.size();
    }
    int longestStrChain(vector<string>& a) {
        sort(a.begin(),a.end(),compa);
        int n = a.size();
        int maxi = 1;
        
        vector<int>dp(n,1);
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(comp(a[i],a[j]) && dp[i]<dp[j]+1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        for(auto x:a) cout<<x<<" ";
        return maxi;
    }
};