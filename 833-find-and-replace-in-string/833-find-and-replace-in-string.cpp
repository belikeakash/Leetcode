class Solution {
public:
    string findReplaceString(string s, vector<int>& p, vector<string>& q, vector<string>& r) {
        map<int,pair<string,string>>m;
        for(int i=0;i<p.size();i++) {
            m[p[i]]={q[i],r[i]};
        }
        string ans = "";
        for(int i=0;i<s.size();i++) {
            if(m.find(i)!=m.end()) {
                string temp = "";
                int k = 0;
                int j = i;
                int len = m[i].first.size();
                while(j<s.size() && k<len) {
                    if(s[j++]==m[i].first[k]) temp.push_back(m[i].first[k++]);
                    else break;
                }
                if(temp==m[i].first) {
                    ans+=m[i].second;
                    i=j-1;
                    continue;
                }
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};