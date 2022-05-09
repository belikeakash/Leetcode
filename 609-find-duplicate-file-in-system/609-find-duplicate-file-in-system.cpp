class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& v) {
        map<string,vector<string>>m;
        for(auto s:v) {
            string a="";
            int i = 0;
            while(s[i]!=' ') {a+=s[i]; i++;}
            cout<<a<<endl;
            i++;
            while(i<s.size()) {
                string b="";
                string c="";
                while(i<s.size() && s[i]!='(') {
                    b+=s[i];
                    i++;
                }
                // i++;
                while(i<s.size() && s[i]!=')') {
                    c+=s[i]; i++;
                }
                i++;
                i++;
                cout<<b<<" "<<c<<endl;
                m[c].push_back(a+'/'+b);
            }
            
        }
        int n = 0;
        for(auto x:m) {
            if(x.second.size()>1) n++;
        }
        cout<<n<<endl;
        vector<vector<string>>ans(n);
        int j = 0;
        for(auto x:m) {
            if(j>=n) break;
            cout<<j<<endl;
            if(x.second.size()>1) {for(auto y:x.second) {ans[j].push_back(y); }j++;}
            
        }
        return ans;
    }
};