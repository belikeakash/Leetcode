class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        int n = a.size();
        int m = a[0].size();
        int l1=0,r1=n-1;
        int l = l1;
        while(l1<=r1) {
            int mid = l1+(r1-l1)/2;
            if(a[mid][0]>x) {
                r1 = mid-1;
            }
            else {
                l = mid;
                l1 = mid+1;
            }
        }
        l1 = l;
        int l2=0,r2=m-1;
        while(l2<=r2) {
            int mid = l2+(r2-l2)/2;
            if(a[l1][mid]==x) {
                return 1;
            }
            else if(a[l1][mid]>x) {
                r2 = mid-1;
            }
            else {
                l2 = mid+1;
            }
        }
        return 0;
    }
};