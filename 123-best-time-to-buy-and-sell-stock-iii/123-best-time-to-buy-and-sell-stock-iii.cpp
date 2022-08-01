class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int>a1(n,0),a2(n,0);
        int mini = a[0];
        for(int i=1;i<n;i++) {
            if(a[i]<mini) mini = a[i];
            a1[i] = max(a1[i-1],a[i]-mini);
        }
        for(auto x:a1) cout<<x<<" ";
        int maxi = a[n-1];
        for(int i=n-2;i>=0;i--) {
            if(a[i]>maxi) maxi = a[i];
            a2[i] = max(a2[i+1],maxi - a[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans,a1[i]+a2[i]);
        }
        return ans;
    }
};