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
        while(i<=j && j<n) {
            bool flag = 0;
            // v[s[j]-'a']++;
            for(int i=0;i<256;i++) {
                if(v[i]>1) {flag = 1; break;}
            }
            // cout<<flag<<" ";
            if(flag==1) {
                v[s[i]]--;
                i++;
                
                // cout<<i<<" ";
            }
            else {
                cout<<i<<"->"<<j<<" ";
                v[s[j]]++;
                ans = max(ans,j-i);
                j++;
            }
        }
        bool flag = 0;
        for(int i=0;i<256;i++) {
            if(v[i]>1) flag = 1;
        }
        if(flag == 0) ans = max(ans,j-i);
        cout<<endl;
        return ans;
    }
};