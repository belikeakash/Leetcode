class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        set<int>s1;
        set<int>s2;
        vector<int>a1;
        vector<int>a2;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j]==0) {
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }
        for(auto x:s1) {a1.push_back(x);}
        for(auto x:s2) {a2.push_back(x);}
        
        for(int i=0;i<a1.size();i++) {
            for(int j=0;j<m;j++) {
                a[a1[i]][j]=0;
            }
        }
        for(int i=0;i<a2.size();i++) {
            for(int j=0;j<n;j++) {
                a[j][a2[i]]=0;
            }
        }
        a1.clear();
        a2.clear();
        s1.clear();
        s2.clear();
        // return a;
    }
};