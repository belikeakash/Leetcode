class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0,n=a.size();
        int mini = a[0];
        for(int i=1;i<n;i++) {
            if(a[i]<mini) mini = a[i];
            ans = max(ans,a[i]-mini);
        }
        return ans;
    }
};