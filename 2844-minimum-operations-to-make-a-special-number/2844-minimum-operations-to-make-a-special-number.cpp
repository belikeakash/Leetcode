class Solution {
public:
    int minimumOperations(string s) {
        string u = "";
        int n = s.size();
        int ans = n;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int x = (s[i]-'0')*10 + (s[j]-'0');
                if(x==0 || x%25==0) {
                    ans = min(ans,(j-i-1)+(n-j-1));
                    cout<<n<<" "<<i<<" "<<j<<" "<<ans<<endl;
                }
            }
        }
        cout<<endl;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') ans = min(ans, n-1);
        }
        return ans;
    }
};