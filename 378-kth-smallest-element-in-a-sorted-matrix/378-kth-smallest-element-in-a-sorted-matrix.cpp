class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n = a.size();
        int t = n*n;
        int l =  a[0][0];
        int r = a[n-1][n-1];
        while(l<=r) {
            int mid = l+(r-l)/2;
            int cnt = 0;
            for(int i=0;i<n;i++) {
                int p = 0,q =n-1;
                while(p<=q) {
                    int m = p+(q-p)/2;
                    if(a[i][m]<=mid) {
                        p = m + 1;
                    }
                    else {
                        q = m - 1;
                    }
                }
                cnt+=p;
            }
            
            if(cnt<=k-1) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
};