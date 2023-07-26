class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int l = 1,r = n-2;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return mid;
            if(a[mid]>a[mid-1] && a[mid]<a[mid+1]) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};