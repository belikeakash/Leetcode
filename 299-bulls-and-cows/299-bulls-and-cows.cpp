class Solution {
public:
    string getHint(string s, string t) {
        //guess == t;
        //secret == t
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(s[i]==t[i]) {
                ans++;
                s[i]='*';
                t[i]='*';
            }
        }
        string res = "";
        res+=to_string(ans);
        res+='A';
        unordered_map<char,int>m1,m2;
        for(auto x:s) {
            m1[x]++;
        }
        for(auto x:t) {
            m2[x]++;
        }
        ans = 0;
        for(int i=0;i<=9;i++) {
            char z = i+'0';
            ans+=min(m1[z],m2[z]);
        }
        res+=to_string(ans);
        res+='B';
        return res;
    }
};