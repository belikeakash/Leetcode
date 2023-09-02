class Solution {
public:
    unordered_map<int, int>mp;
    unordered_map<string, int>m;
    int func(int idx, string s) {
        if(idx>=s.size()) return 0;
        if(mp.count(idx)) return mp[idx]; 
        int ans = 1 + func(idx+1, s);
        string c = "";
        for(int i=idx;i<s.size();i++) {
            c+=s[i];
            if(m[c]) {
                ans = min(ans, func(i+1, s));
            }
        }
        
        return mp[idx] = ans;
    }
    int minExtraChar(string s, vector<string>& v) {
        
        for(auto x:v) m[x]=1;
        return func(0, s);
    }
};