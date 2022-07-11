class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            int l = 0,r = a[i].size()-1;
            while(l<=r) {
                int mid = l + (r-l)/2;
            if(a[i][mid]==t) {
                cout<<a[i][mid]<<" ";
                return 1;
                
            }
            else if(a[i][mid]<t) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
            }
            
        }
        return 0;
    }
};