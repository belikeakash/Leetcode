class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int c = a.size();
        int r = a[0].size();
        for(int i=0;i<c;i++) {
            for(int j=0;j<r;j++) {
                if(i>0 && j>0 && a[i-1][j-1]!=a[i][j]) return 0;
            }
        }
        return 1;
    }
};