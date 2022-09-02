class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        vector<int>v = a[0];
        for(int i=1;i<a.size();i++) {
            vector<int>b;
            for(int j=0;j<a[i].size();j++) {
                for(auto x:v) {
                    b.push_back(a[i][j]+x);
                }
            }
            sort(b.begin(),b.end());
            v.resize(min(k,int(b.size())));
            for(int x=0;x<min(k,int(b.size()));x++) {
                v[x] = b[x];
            }
        }
        return v[k-1];
    }
};