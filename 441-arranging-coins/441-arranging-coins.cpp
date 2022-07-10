class Solution {
public:
    int arrangeCoins(int n) {
        long long int l = 1,r=n,x=n;
        long long int ans=-1;
        while(l<=r) {
            long long int mid = l+(r-l)/2;
            if(mid*(mid+1)<=x*2) {
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return ans;
    }
};