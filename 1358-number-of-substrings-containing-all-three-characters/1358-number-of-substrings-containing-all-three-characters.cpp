class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>a(3,0);
        for(int i=0;i<=2;i++) {
            a[s[i]-'a']++;
        }
        int cnt = 0;
        int n = s.size();
        int ans = 0;
        int i = 0,j=2;
        while(i<j && j<n) {
            cnt = 0;
            for(int i=0;i<=2;i++) {
            if(a[i]>0) cnt++;
        }
            if(cnt==3) {
                ans+=n-j;
                
                a[s[i]-'a']--;
                i++;
            }
            else {j++; if(j<n) a[s[j]-'a']++;}
        }
        return ans;
        
    }
};