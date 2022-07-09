class Solution {
public:
    int maxRepOpt1(string s) {
        if(s.size()<=1) return s.size();
        int n = s.size();
        int ans = 0;
        vector<int>a1(n,1),a2(n,1);
        unordered_map<char,int>m;
        m[s[0]]=1;
        for(int i=1;i<n;i++) {
            m[s[i]]++;
            if(s[i]==s[i-1]) a1[i]=a1[i-1]+1;
            else a1[i]=1;
        }
        for(int i=n-2;i>=0;i--) {
            if(s[i]==s[i+1]) a2[i]=a2[i+1]+1;
            else a2[i]=1;
        }
        for(int i=1;i<n;i++) {
            if(s[i-1]==s[i+1] && s[i-1]!=s[i]) {
                if(m[s[i-1]]==a1[i-1]+a2[i+1]) ans = max(ans,a1[i-1]+a2[i+1]);
                else ans = max(ans,a1[i-1]+a2[i+1] + 1);
            }
            else {
                if(a1[i]==m[s[i]]) ans = max(ans,a1[i]);
                else ans = max(ans,a1[i]+1);
            }
        }
        return ans;
    }
};