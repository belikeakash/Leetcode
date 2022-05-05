class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        int n = s.size();
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='#') {
                string p;
                int x = (s[i-2]-'0')*10 + (s[i-1]-'0')-1;
                char a = (char)(x+97);
                ans+=a;
                cout<<a<<"*";
                i=i-2;
            }
            else {
                string p; 
                p = s[i];
                 
                int x = s[i] - '0'-1;
                char a = (char)(x+97);
                cout<<a<<"$";
                ans+=a;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};