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
                int p = m[i].first.size();
                string temp = "";
                int st = 0;
                int j = i;
                while(st<p && j<s.size()) {
                    temp += s[j];
                    j++;
                    st++;
                }
                cout<<temp<<endl;
                if(temp==m[i].first) {
                    ans+=m[i].second;
                    i=j-1;
                    continue;
                }
            }
            ans+=s[i];
            
        }
        return ans;
    }
};