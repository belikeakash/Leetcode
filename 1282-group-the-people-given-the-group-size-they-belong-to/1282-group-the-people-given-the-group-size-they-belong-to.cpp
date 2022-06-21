class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        vector<vector<int>>ans;
        int n = a.size();
        int p = 1;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++) {
            m[a[i]].push_back(i);
            if(m[a[i]].size()==a[i]) {
                vector<int>b;
                for(auto x:m[a[i]]) {
                    b.push_back(x);
                }
                m[a[i]].clear();
                ans.push_back(b);
            }
        }
        
        return ans;
    }
};