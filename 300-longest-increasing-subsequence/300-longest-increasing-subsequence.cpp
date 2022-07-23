class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++) {
            int ans = 0;
            for(int j=0;j<i;j++) {
                if(a[j]<a[i]) ans = max(ans,v[j]);
            }
            v[i] = ans+1;
        }
        for(auto x:v) cout<<x<<" ";
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans,v[i]);
        }
        return ans;
    }
};