class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int ans = 0;
        for(int i=0;i<a.size();i++) {
            int l = 0,r=a[0].size()-1;
            int p = a[0].size();
            while(l<=r) {
                int mid = l+(r-l)/2;
                if(a[i][mid]>=0) l = mid+1;
                else {
                    p = mid;
                    r = mid-1;
                }
            }
            cout<<l<<" ";
            // if(r==a[0].size()-1) ans+=0;
            ans+=a[0].size()-p;
        }
        return ans;
    }
};