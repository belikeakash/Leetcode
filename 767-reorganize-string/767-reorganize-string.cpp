class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>m;
        for(auto x:s) m[x]++;
        for(auto x:m) {
            if(x.second>(s.size() - 1)/2 + 1) return "";
        }
        string ans = "";
        vector<pair<int,char>>v;
        for(auto x:m) {
            // cout<<x.second<<" "<<x.first<<endl;
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        // s = "";
        // for(auto x:v) {
        //     cout<<x.first<<" "<<x.second<<endl;;
        // }
        // reverse(s.begin(),s.end());
        int j = 0;
        // cout<<v[j].first<<endl;
        for(int i=0;i<s.size();i=i+2) {
            if(v[j].first<=0)j++;
            cout<<v[j].first<<" ";
            s[i] = v[j].second;
            v[j].first--;
        }
        for(int i=1;i<s.size();i=i+2) {
            if(v[j].first<=0)j++;
            cout<<v[j].first<<" ";
            s[i] = v[j].second;
            v[j].first--;
        }
        return s;
    }
};