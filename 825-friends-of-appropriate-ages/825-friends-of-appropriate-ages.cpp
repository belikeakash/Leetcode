class Solution {
public:
    int func(vector<int>&a, int x) {
        int l = 0,r=a.size()-1;
        int ans = 0;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(a[mid]<=x) {
                ans = mid;
                l = mid+1;
            }
            else {
                r=mid-1;
            }
        }
        return l;
    }
    int numFriendRequests(vector<int>& a) {
        sort(a.begin(),a.end());
        int ans = 0;
        int n = a.size();
        for(int i=0;i<n;i++) {
            int r = func(a,a[i]);
            int l = func(a,a[i]/2 + 7);
            ans+=max(0,r-l-1);
            cout<<ans<<" ";
        }
        cout<<endl;
        return ans;
    }
};