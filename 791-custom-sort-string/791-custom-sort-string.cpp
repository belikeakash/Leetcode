class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>v(26,0);
        for(auto x:s) {
            v[x-'a']++;
        }
        string ans = "";
        for(auto x:order) {
            int y = x - 'a';
            while(v[y]>0) {
                ans+=x;
                v[y]--;
            }
        }
        for(int i=0;i<26;i++) {
            while(v[i]>0) {
                char c = (char)i+97;
                ans+=c;
                v[i]--;
            }
        }
        return ans;
    }
};