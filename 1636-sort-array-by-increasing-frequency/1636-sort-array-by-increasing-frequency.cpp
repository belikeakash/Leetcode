class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b) {
        if(a.first==b.first) return a.second > b.second;
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& a) {
        unordered_map<int,int>m;
        for(auto x:a) {
            m[x]++;
        }
        vector<int>ans;
        vector<pair<int,int>>v;
        for(auto x:m) {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto x:v) {
            int k = x.first;
            while(k--) {
                ans.push_back(x.second);
            }
        }
        return ans;
    }
};