class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& a) {
        int n = a.size();
        vector<int>v1,v2;
        int m1=0,m2=0;
        for(int i=0;i<a.size();i++) {
            m1 = 0;
            for(int j=0;j<a[0].size();j++) {
                m1 = max(m1,a[i][j]);
            }
            v1.push_back(m1);
        }
        for(int i=0;i<a.size();i++) {
            m2 = 0;
            for(int j=0;j<a[0].size();j++) {
                m2 = max(m2,a[j][i]);
            }
            v2.push_back(m2);
        }
        for(auto x:v1) {
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:v2) {
            cout<<x<<" ";
        }
        m2 = 0;
        for(int i=0;i<a.size();i++) {
            for(int j=0;j<a[0].size();j++) {
                m2 += abs(a[i][j] - min(v1[i],v2[j])); 
            }
        
        }
        return m2;
    }
};