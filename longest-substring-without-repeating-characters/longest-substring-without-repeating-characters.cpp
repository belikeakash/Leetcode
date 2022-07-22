class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        if(s.size()<2) return s.size();
        vector<int>v(256,0);
        for(auto x:s) {
            v[x]++;
        }
        int c = 0;
        for(int i=0;i<256;i++) {
            if(v[i]>0) c++;
            v[i] = 0;
        }
        // cout<<c<<endl;
        int i = 0,j = 0;
        int ans = 0;
        while(j<n) {
            v[s[j]]++;
            while(v[s[j]]>1) {
                v[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        
        cout<<endl;
        return ans;
    }
};