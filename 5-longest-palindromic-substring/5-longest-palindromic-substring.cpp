class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l=0,r=0,st=0,en=0;
        for(int i=1;i<n;i++) {
            l = i-1;
            r = i;
            while(l>=0 && r<n && s[l]==s[r]) {
                if(r-l > en-st) {
                    st = l;
                    en = r;
                }
                l--;
                r++;
            }
            l = i-1;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]) {
                if(r-l > en-st) {
                    st = l;
                    en = r;
                }
                l--;
                r++;
            }
        }
        string ans = "";
        for(int i=st;i<=en;i++) {
            ans+=s[i];
        }
        return ans;
    }
};