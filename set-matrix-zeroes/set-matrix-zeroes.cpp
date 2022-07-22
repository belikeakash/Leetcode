class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        // set<int>s1;
        // set<int>s2;
        // vector<int>a1;
        // vector<int>a2;
        int p1=0,p2=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j]==0) {
                    // s1.insert(i);
                    // s2.insert(j);
                    if(i==0) p1=1;
                    if(j==0) p2=1;
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
//         for(auto x:s1) {a1.push_back(x);}
//         for(auto x:s2) {a2.push_back(x);}
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(a[i][0]==0 || a[0][j]==0) {
                    a[i][j]=0;
                }
            }
        }
        if(p1==1) {
            for(int i=0;i<m;i++) a[0][i]=0;
        }
        if(p2==1) {
            for(int i=0;i<n;i++) a[i][0]=0;
        }
        // return a;
    }
};