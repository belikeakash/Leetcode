class Solution {
public:
    int threeSumMulti(vector<int>& a, int x) {
        int n = a.size();
        sort(a.begin(),a.end());
        int ans = 0;
        int mod = 1e9 + 7;
        for(int i=0;i<n-2;i++) {
            int l = i+1;
            int r = n-1;
            while(l<r) {
                if(a[i]+a[l]+a[r]==x) {
                    int x=1;
                    int y=1;
                    while(l<r && a[l]==a[l+1]) {
                        l++;
                        x++;
                    }
                    while(l<r && a[r]==a[r-1]) {
                        r--;
                        y++;
                    }
                    if(l==r) {
                        ans=(ans+(x*(x-1)/2))%mod;
                    }
                    else {
                        ans=(ans+(x*y))%mod;
                    }
                    l++;
                    r--;
                }
                else if(a[i]+a[l]+a[r]<x) {
                    l++;
                }
                else r--;
            }
        }
        return ans%mod;
    }
};