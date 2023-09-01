class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        long long ans = 0;
        int j = 1, i = 0;
        int n = a.size();
        while(j<n) {
            if(a[j-1]-a[j]==1) {
                cout<<j<<" ";
                ans+=j-i;
                j++;
            }
            else {
                i = j;
                j = i+1;
            }
        }
        return ans+n;
    }
};