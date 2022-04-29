class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& a) {
        vector<vector<int>>v(m,vector<int>(n,0));
        for(auto x:a) {
            int p = x[0];
            int q = x[1];
            for(int i=0;i<n;i++) {
                v[p][i]+=1;
            }
            for(int j=0;j<m;j++) {
                v[j][q]+=1;
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++){
                // cout<<v[i][j]<<" ";  
                if(v[i][j]%2!=0) cnt++;
            }
            // cout<<endl;
        }
        return cnt;
    }
};