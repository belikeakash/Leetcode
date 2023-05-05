class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int ans = 0;
        left[0] = a[0];
        for(int i=1;i<n;i++) {
            int x = max(a[i],left[i-1]);
            left[i] = x;
        }
        right[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--) {
            int x = max(a[i], right[i+1]);
            right[i] = x;
        }
        
        for(int i=1;i<n-1;i++) {
            ans+= min(left[i],right[i]) - a[i];
        }
        return ans;
    }
};