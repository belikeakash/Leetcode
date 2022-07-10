class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        sort(a.begin(),a.end());
        int l = 1,r=a[n-1];
        int ans = a[n-1];
        while(l<=r) {
            int mid = l+(r-l)/2;
            long long cnt = 0;
            for(int i=0;i<n;i++) {
                cnt+=(a[i]-1)/mid + 1;
            }
            if(cnt<=h) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};