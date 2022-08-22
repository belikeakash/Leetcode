class Solution {
public:
    bool isPal(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return s==t;
    }
    vector<vector<string>>ans;
    vector<string>v;
    void func(int i, string s) {
        if(i==s.size()) {
            for(auto x:v) {
                if(!isPal(x)) return;
            }
            ans.push_back(v);
            return ;
        }
        string p = "";
        for(int j=i;j<s.size();j++) {
            p+=s[j];
            v.push_back(p);
            func(j+1,s);
            v.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        func(0,s);
        // vector<vector<string>>res;
        // for(auto x:ans) {
        //     string u = "";
        //     for(auto y:x) u+=y;
        //     if(u.size()==s.size()) res.push_back(x);
        // }
        return ans;
    }
};