class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int i = 0,j = n-1;
        while(i<j) {
            int h = min(a[i],a[j]);
            // cout<<ans<<" ";
            ans = max(ans,(j-i)*h);
            while(a[i]<=h && i<j) i++;
            while(a[j]<=h && i<j) j--;
            // cout<<ans<<"  "<<h<<endl;
            cout<<ans<<" "<<i<<" "<<j<<endl;
        }
        return ans;
    }
};