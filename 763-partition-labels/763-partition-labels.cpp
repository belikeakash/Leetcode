class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,pair<int,int>>m;
        int p,q;
        for(int i=0;i<s.size();i++) {
            if(m.count(s[i])) {
                p = m[s[i]].first;
                q = i;
            }
            else {
                p = i;
                q = i;
            }
            m[s[i]] = {p,q};
        }
        vector<pair<int,int>>v;
        for(auto x:m) {
            v.push_back(x.second);
        }
        vector<int>ans;
        sort(v.begin(),v.end());
        int st = v[0].first;
        int en = v[0].second;
        for(int i=1;i<v.size();i++) {
            if(v[i].first<en) {
                en = max(en,v[i].second);
            }
            else {
                ans.push_back(en-st+1);
                st = v[i].first;
                en = v[i].second;
            }
        }
        ans.push_back(en-st+1);
        return ans;
    }
};