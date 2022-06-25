class Solution {
public:
    int minPairSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        int ans = INT_MIN;
        for(int i=0;i<n/2;i++) {
            ans = max(ans,a[i]+a[n-i-1]);
        }
        return ans;
    }
};