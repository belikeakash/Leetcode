class Solution {
public:
    int smallestDivisor(vector<int>& a, int x) {
        int n = a.size();
        sort(a.begin(),a.end());
        // if(n==x) return a[n-1];
        int l = 1,r=a[n-1];
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt = 0;
            for(int i=0;i<n;i++) {
                cnt+= (a[i]-1)/mid + 1;
            }
            if(cnt<=x) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
            cout<<cnt<<" ";
        }
        return ans;
    }
};