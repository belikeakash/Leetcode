class Solution {
public:
    string convertToTitle(int n) {
        string s = "*ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans = "";
        int x;
        while(n>26) {
            x = n%26;
            n=(n-1)/26;
            if(x==0) x = 26;
            ans.push_back(s[x]);
        }
        x = n%26;
        if(x==0) x = 26;
            ans.push_back(s[x]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};