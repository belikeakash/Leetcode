class Solution {
public:
    bool wordPattern(string t, string s) {
        vector<string>v;
        string k = "";
        for(int i=0;i<s.size();i++) {
            
            if(s[i]==' ') {
                v.push_back(k);
                k = "";
            }
            else k+=s[i];
        }
        v.push_back(k);
        for(auto x:v) cout<<x<<" ";
        cout<<endl;
        if(t.size()!=v.size()) return 0;
        map<char,string>m;
        for(int i=0;i<t.size();i++) {
            if(m.count(t[i])==0) {for(auto x:m) {
                if(x.second==v[i]) return 0;
            } m[t[i]] = v[i];}
            else {
                
                if(m[t[i]]!=v[i]) return 0;
            }
        }
        return 1;
    }
};