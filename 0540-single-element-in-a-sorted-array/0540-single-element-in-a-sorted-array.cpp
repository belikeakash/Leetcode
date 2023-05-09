class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        if(n==1) return a[0];
        int l = 0,r=n-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(mid-1>=0 && a[mid]!=a[mid-1] && mid+1<n && a[mid]!=a[mid+1]) return a[mid];
            else if(mid-1<0 && a[mid]!=a[mid+1]) {
                return a[mid];
            }
            else if(mid+1>=n && a[mid]!=a[mid-1]) {
                return a[mid];
            }
            else if((mid % 2 == 0 && a[mid] == a[mid + 1]) || (mid % 2 == 1 && a[mid] == a[mid - 1]))
			l = mid + 1;
		else
			r = mid-1;
        }
        return -1;
    }
};