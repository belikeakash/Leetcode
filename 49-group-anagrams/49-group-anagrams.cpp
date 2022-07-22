class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        map<string,vector<string>>m;
        for(auto x:v) {
            string s = x;
            sort(s.begin(),s.end());
            m[s].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto x:m) {
            vector<string>a;
            for(auto y:x.second) a.push_back(y);
            ans.push_back(a);
        }
        return ans;
    }
};