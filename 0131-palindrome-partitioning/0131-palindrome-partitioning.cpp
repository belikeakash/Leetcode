class Solution {
public:
    vector<string>v;
    vector<vector<string>>ans;
    bool isPal(vector<string>&v) {
        for(int j=0;j<v.size();j++){
                string s = v[j];
                for(int i=0;i<s.size()/2;i++) {
                if(s[i]!=s[s.size()-1-i]) return 0;
            }
        }
        
        return 1;
    }
    void func(int i, string s, string x) {
        if(i>=s.size()) {
            if(isPal(v)) {
                ans.push_back(v);
            }
            return;
        }
        x = "";
        for(int j=i;j<s.size();j++) {
            x+=s[j];
            v.push_back(x);
            func(j+1,s,x);
            v.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        func(0,s,"");
        return ans;
    }
};