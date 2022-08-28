class Solution {
public:
    set<string>p;
    vector<string>ans;
    void func(int i, string s) {
        if(i==s.size()) {
            p.insert(s);
            return;
        }
        char c = s[i];
        c = toupper(c);
        s[i]=c;
        func(i+1,s);
        c = tolower(c);
        s[i]=c;
        func(i+1,s);
    }
    vector<string> letterCasePermutation(string s) {
        func(0,s);
        for(auto x:p) ans.push_back(x);
        return ans;
    }
};