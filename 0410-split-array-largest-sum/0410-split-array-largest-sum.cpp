class Solution {
public:
    int func(vector<int>&a, int x , int mid) {
        int n = a.size();
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<n;i++) {
            if(a[i]>mid) return 0;
            if(a[i]+sum > mid) {
                cnt++;
                sum = a[i];
                if(cnt>x) return 0;
            }
            else sum+=a[i];
        }
        return 1;
    }
    int splitArray(vector<int>& a, int k) {
        int n = a.size();
        int l = 0,r=INT_MAX;
        int ans = 0;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(func(a,k,mid)) {
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