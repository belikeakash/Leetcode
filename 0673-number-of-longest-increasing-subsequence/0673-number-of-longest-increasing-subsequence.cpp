class Solution {
public:
    
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int>v1(n,1),v2(n,1);
        int gmax = 1;
        for(int i=1;i<n;i++) {
            int maxi = 0;
            for(int j=0;j<i;j++) {
                if(a[j]<a[i]) {
                    maxi = max(maxi, v1[j]);
                }
            }
            v1[i] = maxi+1;
            gmax = max(gmax, v1[i]);
            int cnt = 0;
            for(int j=0;j<i;j++) {
                if(v1[j]==v1[i]-1 && a[i]>a[j]) cnt+=v2[j];
            }
            v2[i] = max(1,cnt);
        }
        int ans = 0;
        cout<<gmax<<endl;
        for(auto x:v1) cout<<x<<" ";
        cout<<endl;
        for(auto x:v2) cout<<x<<" ";
        cout<<endl;
        for(int i=0;i<v2.size();i++) {
            if(v1[i]==gmax) ans+=v2[i];
        }
        
        return ans;
    }
};