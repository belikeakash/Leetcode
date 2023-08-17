class Solution {
public:
    bool isPow(string s) {
        int n = s.size();
        int x = 0;
        //cout<<s<<" ";
        if(s[0]=='0') return 0;
        for(int i=0;i<n;i++) {
            x = x*2 + (s[i]=='1');
        }
        if(x==0) return 0;
        //if(x==1) return 1;
        while(x%5==0) {
            //cout<<x<<" ";
            x = x/5;
            
        }
        return x==1;
    }
    int func(int i, string s) {
        if(i>=s.size()) return 0;
        if(s[i]==0) return INT_MAX;
        int ans = INT_MAX;
        string c = "";
        for(int j=i;j<s.size();j++) {
            c+=s[j];
            if(isPow(c)) {
                //cout<<j<<"->"<<c<<" ";
                int u = func(j+1, s);
                if(u!=INT_MAX) u = 1 + u;
                ans = min(ans, u);
            }
        }
        //cout<<endl;
        
        return ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int ans = func(0, s);
        return ans==INT_MAX?-1:ans;
    }
};