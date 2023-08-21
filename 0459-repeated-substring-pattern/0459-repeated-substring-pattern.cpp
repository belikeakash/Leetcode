class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string c = "";
        for(int i=0;i<n;i++) {
            c+=s[i];
            if(n%(c.size())!=0) continue;
            bool flag = 0;
            for(int j=0;j<n;j+=c.size()) {
                for(int k=0;k<c.size();k++) {
                    if(s[k+j]!=c[k]) {
                        flag = 1;
                        //cout<<i<<" ";
                        break;
                    }
                }
            }
            if(!flag && c!=s) {cout<<c<<" "; return 1;}
        }
        
        return 0;
    }
};