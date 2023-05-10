class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        map<int,int>m;
        for(auto x:a) {
            m[x]++;
        }
        vector<pair<int,int>>v;
        for(auto x:m) {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int>ans;
        int i = 0;
        while(k--) {
            ans.push_back(v[i].second);
            i++;
        }
        return ans;
    }
};