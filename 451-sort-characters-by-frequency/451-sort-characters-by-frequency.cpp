class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(auto x:s) {
            m[x]++;
        }
        vector<pair<int,char>>v;
        for(auto x:m) {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        string ans = "";
        for(auto x:v) {
            for(int i=0;i<x.first;i++) ans+=x.second;
        }
        return ans;
    }
};