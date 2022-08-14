class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int>ans(n,1);
        for(int i=1;i<n;i++) {
            if(a[i]>a[i-1]) ans[i]=ans[i-1]+1;
            else ans[i] = 1;
        }
        for(int i=n-2;i>=0;i--) {
            if(a[i]>a[i+1] && ans[i]<ans[i+1]+1) {
                ans[i] = ans[i+1]+1;
            }
        }
        int resx=0;
        for(auto x:ans) {
            resx+=x;
        }
        return resx;
    }
};