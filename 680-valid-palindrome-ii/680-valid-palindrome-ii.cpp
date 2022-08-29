class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l=-1,r=-1;
        for(int i=0;i<n/2;i++) {
            if(s[i]!=s[n-i-1]) {
                l = i;
                r = n-i-1;
                break;
            }
        }
        if(l==-1 && r==-1) return 1;
        int p=l+1,q=r;
        int ans = 0;
        while(p<=q) {
            if(s[p]!=s[q]) {
                ans++;
                break;
            }
            p++;
            q--;
        }
        p=l,q=r-1;
        while(p<=q) {
            if(s[p]!=s[q]) {
                ans++;
                break;
            }
            p++;
            q--;
        }
        if(ans>=2) return 0;
        return 1;
    }
};