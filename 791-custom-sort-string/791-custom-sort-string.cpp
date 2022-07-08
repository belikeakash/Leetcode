class Solution {
public:
    string customSortString(string t, string s) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        int i = 1;
        string ans = "";
        for(auto x:s) {
            b[x-'a']++;
        }
        for(auto x:t) {
            if(b[x-'a']>0) {
                while(b[x-'a']-- >0) ans+=char(x-'a'+97);
            }
        }
        for(int i=0;i<26;i++) {
            if(b[i]>0) {
                while(b[i]-- >0) ans+=char(i+97);
            }
        }
        return ans;
        
    }
};