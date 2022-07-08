class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>a(26,0),b(26,0);
        for(auto x:s) {
            a[x-'a']++;
        }
        for(auto x:t) {
            b[x-'a']++;
        }
        int ans = 0;
        for(int i=0;i<26;i++) {
            if(b[i]>a[i]) ans += b[i]-a[i];
        }
        return ans;
    }
};