class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        vector<int>ans(n,0);
        vector<int>l(n,0),r(n,0);
        int x = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                x++;
                ans[0]+=i;
            }
            l[i]=x;
        }
        x=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='1') x++;
            r[i]=x;
        }
        // reverse(r.begin(),r.end());
        x=0;
        // for(int i=1;i<n;i++) {
        //     if(s[i]=='1') ans[0]+=i;
        // }
        // ans[0] = x;
        for(auto x:l) cout<<x<<" ";
        cout<<endl;
        for(auto x:r) cout<<x<<" ";
        for(int i=1;i<n;i++) {
            ans[i] = ans[i-1] + l[i-1] - r[i];
            // if(s[i]=='1') ans[i]-=2;
        }
        return ans;
    }
};