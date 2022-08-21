class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        int n = s.size();
        string x = "";
        for(int i=0;i<n;i++) {
            if(s[i]==' ') {
                if(x!="") {v.push_back(x); x="";}
                else x="";
            }
            else x+=s[i];
        }
        if(x!="")v.push_back(x);
        reverse(v.begin(),v.end());
        s = "";
        for(auto y:v) {
            s+=y;
            s+=" ";
        }
        s.pop_back();
        return s;
    }
};