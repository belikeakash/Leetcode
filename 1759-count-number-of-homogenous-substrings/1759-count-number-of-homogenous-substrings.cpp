class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int mod = 1000000007;
        int k = 1;
        long long ans = 0;
        for(int i=1;i<n;i++) {
            if(s[i]==s[i-1]) {
                k++;
            }
            else {
                ans+=(long long)(k*(k+1))/2;
                ans=ans%mod;
                k=1;
            }
        }
        ans+= ((long long)k*(k+1))/2;
        ans = ans%mod;
        return ans;
    }
};