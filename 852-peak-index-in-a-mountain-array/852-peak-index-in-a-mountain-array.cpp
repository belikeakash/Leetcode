class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int l = 0,r = n-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(mid>=1 && mid<n-1 && a[mid]>a[mid-1] && a[mid]>a[mid+1]){
                return mid;
            }
            else if(mid>=1 && mid<n-1 && a[mid]<a[mid-1] && a[mid]>a[mid+1]) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return -1;
    }
};