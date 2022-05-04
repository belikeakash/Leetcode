class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<n/2;i++) {
            for(int j=0;j<m;j++) {
                swap(a[i][j],a[n-i-1][j]);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                swap(a[i][j],a[j][i]);
            }
        }
    }
};