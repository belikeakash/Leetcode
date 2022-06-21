class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        vector<vector<int>>ans;
        int n = a.size();
        int p = 1;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++) {
            m[a[i]].push_back(i);
        }
        for(auto x:m) {
            int i = 0;
            while(i<x.second.size()) {
                    vector<int>b;  
                    for(int j=0;j<x.first;j++) {
                        b.push_back(x.second[i]);
                        i++;
                    }
                ans.push_back(b);
            }
            
            
            
        }
        return ans;
    }
};