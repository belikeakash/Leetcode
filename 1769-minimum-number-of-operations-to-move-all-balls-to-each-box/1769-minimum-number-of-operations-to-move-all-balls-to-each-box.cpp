class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int>a;
        int n = s.size();
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            
            ans+=cnt;
            a.push_back(ans);
            if(s[i]=='1') cnt++;
        }
        for(auto u:a) {
            cout<<u<<" ";
        }
        int x = 0;
        int p = 0;
        for(int i=1;i<n;i++) {
            if(s[i]=='1') p+=i;
        }
        vector<int>y;
        y.push_back(p);
        if(s[0]=='1')cnt--;
        for(int i=1;i<n;i++){
         
            p = p - (cnt);
               if(s[i]=='1') cnt--;
            y.push_back(p+a[i]);
        }
        return y;
    }
};