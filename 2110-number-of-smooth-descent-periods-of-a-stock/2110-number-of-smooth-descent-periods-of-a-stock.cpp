class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        long long ans = 0;
        int j = 1, i = 0;
        int n = a.size();
        while(j<n) {
            //cout<<j<<" ";
            while(j<n && a[j-1]-a[j]==1) {
                j++;
            }
            
            ans+=1LL*((1LL*(j-i))*(1LL*(j-i-1)))/2;
                i = j;
                j = i+1;
            
        }
        cout<<endl;
        return ans+n;
    }
};