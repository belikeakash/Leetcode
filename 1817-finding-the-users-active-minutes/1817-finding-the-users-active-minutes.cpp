class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& a, int k) {
        int n = a.size();
        vector<int>ans(k,0);
        map<int,set<int>>m;
        for(auto x:a) {
            m[x[0]].insert(x[1]);
        }
        for(auto x:m) {
            ans[x.second.size()-1]++;
        }
        return ans;
    }
};