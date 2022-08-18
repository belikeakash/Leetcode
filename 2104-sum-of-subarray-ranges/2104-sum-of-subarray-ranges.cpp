class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
        int n = a.size();
        // vector<int>left(n,0);
        // vector<int>right(n,0);
        // for(int i=0;i<n;i++) {
        //     left[i] = i;
        //     right[i] = n-i-1;
        // }
        // stack<int>s;
        // for(int i=0;i<n;i++) {
        //     while(!s.empty() && a[s.top()]>a[i]) {
        //         right[s.top()] = i-s.top()-1;
        //         s.pop();
        //     }
        //     s.push(i);
        // }
        // stack<int>s2;
        // for(int i=n-1;i>=0;i--) {
        //     while(!s.empty() && a[s.top()]>a[i]) {
        //         left[s.top()] = s.top()-i-1;
        //         s.pop();
        //     }
        //     s.push(i);
        // }
        // int ans = 0;
        // for(int i=0;i<n;i++) {
        //     ans+= (long long)(right[i]+1)*(left[i]+1);
        //     ans%=1000000007;
        // }
        // return ans;
        int mini;
        int maxi;
        int mod = 1000000007;
        long long ans = 0;
        for(int i=0;i<n;i++) {
            mini = a[i];
            maxi = a[i];
            for(int j=i;j<n;j++) {
                mini = min(mini,a[j]);
                maxi = max(maxi,a[j]);
                ans+= (maxi - mini);
                // ans%=mod;
                // cout<<ans<<" ";
            }
        }
        return ans;
    }
};