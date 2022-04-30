class Solution {
public:
    int countCharacters(vector<string>& v, string s) {
        map<char,int>m;
        int ans = 0;
        for(int i=0;i<s.size();i++) m[s[i]]++;
        for(int i=0;i<v.size();i++) {
            string x = v[i];
            bool flag = 1;
            map<char,int>p;
            for(int j=0;j<x.size();j++) {
                p[x[j]]++;
                if(p[x[j]] > m[x[j]]) {flag = 0; continue;}
                if(m[x[j]]>0) {
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