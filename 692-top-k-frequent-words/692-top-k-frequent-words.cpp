class Solution {
public:
    static bool cmp(pair<int,string>&a,pair<int,string>&b) {
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& w, int k) {
        unordered_map<string,int>m;
        for(auto x:w) {
            m[x]++;
        }
        vector<pair<int,string>>v;
        for(auto x:m) {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),cmp);
        vector<string>ans;
        int i = 0;
        while(k--) {
            ans.push_back(v[i].second);
            i++;
        }
        return ans;
    }
};