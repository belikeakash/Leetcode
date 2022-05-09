class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        unordered_map<string,vector<string>>m;
        for(auto x:v) {
            string p = x;
            sort(x.begin(),x.end());
            m[x].push_back(p);
        }
        int n = m.size();
        vector<vector<string>>ans(n);
        int i = 0;
        for(auto x:m) {
            for(auto y:x.second) ans[i].push_back(y);
            i++;
        }
        return ans;
    }
};