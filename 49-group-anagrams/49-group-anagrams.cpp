class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        map<vector<int>,vector<string>>m;
        vector<int>a(26,0);
        for(auto x:v) {
            for(int i=0;i<26;i++) a[i] = 0;
            for(auto y:x) a[y-'a']++;
            m[a].push_back(x);
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