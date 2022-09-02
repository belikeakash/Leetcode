class Solution {
public:
    static bool cmp(pair<vector<int>,int>&a,pair<vector<int>,int>&b) {
        return a.second<b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        vector<pair<vector<int>,int>>v;
        for(auto x:a) {
            int u = x[1]*x[1] + x[0]*x[0];
            v.push_back({x,u});
        }
        sort(v.begin(),v.end(),cmp);
        vector<vector<int>>ans;
        int i = 0;
        while(k--) {
            ans.push_back(v[i].first);
            i++;
        }
        return ans;
    }
};