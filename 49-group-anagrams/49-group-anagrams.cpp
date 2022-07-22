class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        map<vector<int>,vector<string>>m;
        for(auto x:v) {
            vector<int>a(26,0);
            for(auto y:x) {
                a[y-'a']++;
            }
            m[a].push_back(x);
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