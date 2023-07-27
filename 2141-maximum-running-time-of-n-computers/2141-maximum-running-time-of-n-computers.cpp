class Solution {
public:
    int func(vector<int>&a, long long mid, int x) {
        int n = a.size();
        int cnt = 0;
        long long sum = 0;
        for(int i=0;i<n;i++) {
            if(a[i]>=mid) {
                sum+=mid;
            }
            else {
                sum+=a[i];
            }
            if(sum>=mid*x) return 1;
            
        }
        
        return 0;
    }
    long long maxRunTime(int n, vector<int>& a) {
        int sz = a.size();
        long long l = 0, r=0;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for(auto x:a) r+=x;
        r = r/n;
        long long ans = -1;
        while(l<=r) {
            long long mid = l+(r-l)/2;
            int res = func(a, mid, n);
            cout<<mid<<" "<<res<<endl;
            if(res) {
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