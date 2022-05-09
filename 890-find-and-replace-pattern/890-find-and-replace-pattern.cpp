class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& v, string p) {
        int i = 0;
        unordered_map<char,int>m;
        int n = p.size();
        string os = "";
        for(auto x:p) {
            if(m.count(x)) os+=to_string(m[x]);
            else {
                os+=to_string(i);
                m[x]=i;
                i++;
            }
        }
        cout<<os<<endl;
        vector<string>ans;
        for(auto s:v) {
                if(s.size()!=n) continue;
                int i = 0;
                unordered_map<char,int>m;
            // int n = p.size();
                string op = "";
                for(auto x:s) {
                if(m.count(x)) op+=to_string(m[x]);
                else {
                    op+=to_string(i);
                    m[x]=i;
                    i++;
                }
            }
            if(op==os) ans.push_back(s);
        }
        
        return ans;
    }
};