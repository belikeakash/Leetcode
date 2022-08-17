class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>v(26,0);
        int i = 0,j=0;
        int p = 0;
        int maxi = 0;
        int ans = 0;
        int n = s.size();
        while(j<n) {
            v[s[j]-'A']++;
            for(int u=0;u<26;u++) {
                p = max(p,v[u]);
            }
            if(j-i+1-p>k) {
                v[s[i]-'A']--;
                i++;
                
            }
            ans = max(ans,j-i+1);
            j++;
        }
        cout<<endl;
        return ans;
    }
};