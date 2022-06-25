class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int ans = min(a[0],a[n-1])*(n-1);
        int i = 0,j = n-1;
        while(i!=j) {
            ans = max(ans,min(a[i],a[j])*(j-i));
            if(a[i]>a[j]) {
                j--;
            }
            else {
                i++;
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};