class Solution {
public:
    int countCharacters(vector<string>& v, string s) {
        vector<int>m(27,0);
        int ans = 0;
        for(int i=0;i<s.size();i++) m[s[i]-'a']++;
        for(int i=0;i<v.size();i++) {
            string x = v[i];
            bool flag = 1;
            vector<int>p(27,0);
            for(int j=0;j<x.size();j++) {
                p[x[j]-'a']++;
                if(p[x[j]-'a'] > m[x[j]-'a']) {flag = 0; continue;}
                if(m[x[j]-'a']>0) {
                    continue;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans+=x.size();
        }
        return ans;
    }
};