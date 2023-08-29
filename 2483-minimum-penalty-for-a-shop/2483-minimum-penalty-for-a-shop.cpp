class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int>v(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='N') cnt++;
            v[i] = cnt;
        }
        // for(auto x:v) cout<<x<<" ";
        // cout<<endl;
        int ans = n;
        int mini = INT_MAX;
        cnt = 0;
        for(int i=n-1;i>=0;i--) {
            
            if(v[i]+cnt<=mini) {
                //cout<<v[i]<<" "<<cnt<<" "<<i<<endl;
                mini = v[i]+cnt;
                ans = i+1;
            }
            if(s[i]=='Y') cnt++;
        }
        if(cnt<=mini) ans = 0;
        cout<<endl;
        return ans;
    }
};