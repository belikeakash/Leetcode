class Solution {
public:
    int maxNumberOfBalloons(string s) {
        vector<int>v(26,0);
        int n = s.size();
        for(int i=0;i<n;i++) v[s[i]-'a']++;
        string x = "baloon";
        int ans = INT_MAX;
        v[14] = v[14]/2;
        v[11] = v[11]/2;
        for(int i=0;i<x.size();i++) {
            ans = min(ans,v[x[i]-'a']);
        }
        for(int i=0;i<26;i++) cout<<v[i]<<" ";
        return ans;
        
        
    }
};