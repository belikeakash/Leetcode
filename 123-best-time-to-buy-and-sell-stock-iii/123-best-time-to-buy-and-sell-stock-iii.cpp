class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int>a1(n,0);
        vector<int>a2(n,0);
        int mini = a[0];
        vector<int>p1(n,0);
        for(int i=1;i<n;i++) {
            if(a[i]<mini) mini = a[i];
            a1[i] = a[i]-mini;
            p1[i] = max(p1[i-1],a1[i]);
        }
        
        // for(auto x:p1) cout<<x<<" ";
        int maxi = a[n-1];
        vector<int>p2(n,0);
        for(int i=n-2;i>=0;i--) {
            if(a[i]>maxi) maxi = a[i];
            a2[i] = maxi - a[i];
            p2[i] = max(p2[i+1],a2[i]);
        }
        cout<<endl;
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans,p1[i]+p2[i]);
        }
        
        return ans;
    }
};