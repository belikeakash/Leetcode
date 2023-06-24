class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        int n = __gcd(n1, n2);
        string ans = "";
        cout<<n<<endl;
        for(int i=0;i<n;i++) {
            if(s1[i]==s2[i]) ans+=s1[i];
            else break;
        }
        for(int i=n;i<n1;i+=n) {
            //if(i+n>=n1) return "";
            for(int j=0;j<n;j++) {
                if(ans[j]!=s1[i+j]) return "";
            }
        }
        for(int i=n;i<n2;i+=n) {
            //if(i+n>=n2) return "";
            for(int j=0;j<n;j++) {
                if(ans[j]!=s2[i+j]) return "";
            }
        }
        return ans;
    }
};