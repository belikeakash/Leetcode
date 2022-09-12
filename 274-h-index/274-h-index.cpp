class Solution {
public:
    int hIndex(vector<int>& a) {
        sort(a.begin(),a.end());
        int l = 0,n=a.size(),r=a[n-1];
        int ans = a[0];
        while(l<=r) {
            int mid = (l+r)/2;
            int x=0;
            int y=0;
            for(int i=0;i<n;i++) {
                if(a[i]>=mid) x++;
                if(a[i]<mid) y++;
            }
            cout<<x<<" "<<y<<" "<<mid<<endl;
            if(x>=mid) {
                cout<<"a";
                ans = mid;
                l = mid+1;
            }
            else {
                cout<<"b";
                r = mid-1;
            }
            // cout<<l<<" "<<r<<endl;
        }
        return ans;
    }
};