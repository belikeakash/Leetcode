class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>v1(27,0);
        vector<int>v2(27,0);
        for(auto x:s) {
            v1[x-'a']++;
        }
        for(auto x:t) {
            v2[x-'a']++;
        }
        int ans = 0;
        for(int i=0;i<26;i++) {
            ans += max(0,v1[i]-v2[i]);
        }
        return ans;
    }
};