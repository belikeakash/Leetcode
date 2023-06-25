class Solution {
public:
    string func(int i, string s) {
        if(i==s.size()) return "";
        string t = "";
        while(i<s.size() && s[i]==' ') {
            i++;
        }
        while(i<s.size() && s[i]!=' ') {
            t+=s[i];
            i++;
        }
        string c = func(i, s);
        string ans = c;
        if(t!="") ans=ans + " " + t;
        return ans;
    }
    string reverseWords(string s) {
        string ans = func(0, s);
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};