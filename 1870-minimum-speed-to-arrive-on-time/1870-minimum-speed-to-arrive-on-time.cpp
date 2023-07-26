class Solution {
public:
    double func(vector<int>&a, int mid) {
        double ans = 0;
        int n = a.size();
        for(int i=0;i<n-1;i++) {
            ans+=ceil((double)a[i]/(double)mid);
            //cout<<ceil(a[i]/mid)<<" ";
        }
        //cout<<ans<<" ";
        ans+=(double)(a[n-1])/(double)mid;
        //cout<<ans<<"->";
        return ans;
    }
    int minSpeedOnTime(vector<int>& a, double hour) {
        int l = 1, r = 1e7;
        int ans = -1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            double res = func(a, mid);
            //cout<<res<<" "<<mid<<endl;
            if(res>hour) {
                l = mid+1;
            }
            else {
                ans = mid;
                r = mid-1;
            }
        }
        
        return ans;
    }
};