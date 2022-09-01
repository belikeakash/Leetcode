class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int ans = n;
        int k = n/4;
        unordered_map<char,int>m;
        for(auto x:s) m[x]++;
        
        int a = max(0,m['Q'] - k);
        int b = max(0,m['W'] - k);
        int c = max(0,m['E'] - k);
        int d = max(0,m['R'] - k);
        m.clear();
        unordered_map<char,int>m2;
        int i = 0,j=0;
        for(int j=0;j<n;j++) {
            m2[s[j]]++;
            if(m2['Q']>=a && m2['W']>=b &&  m2['E']>=c && m2['R']>=d) {
                ans = min(ans,j-i+1);
                while(i<=j) {
                    m2[s[i]]--;
                    i++;
                    if(m2['Q']>=a && m2['W']>=b &&  m2['E']>=c && m2['R']>=d) ans = min(ans,j-i+1);
                    else break;
                }
            }
        }
        return ans;
    }
};