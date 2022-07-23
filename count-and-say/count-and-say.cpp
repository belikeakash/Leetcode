class Solution {
public:
    void func(int n, string &s ) {
        
        if(n==1) {
            s+="1";
            return;
        }
        if(n>1) func(n-1,s);
        int c = 1;
        string p = "";
        for(int i=1;i<s.size();i++) {
            if(s[i]==s[i-1]) {
                c++;
            }    
            else {
                p+=to_string(c);
                p+=(s[i-1]);
                c=1;
            }
        }
        p+=to_string(c);
        p+=(s[s.size()-1]);
        s = p;
        // func(n-1,s);
    }
    string countAndSay(int n) {
        string ans = "";
        func(n,ans);
        return ans;
    }
};