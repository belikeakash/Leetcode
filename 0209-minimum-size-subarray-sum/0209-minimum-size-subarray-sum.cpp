class Solution {
public:
    int minSubArrayLen(int x, vector<int>& a) {
        int n = a.size();
        int i = 0, j=0;
        int sum = 0;
        int ans = INT_MAX;
        while(j<n) {
            sum+=a[j];
            while(sum>=x) {
                ans = min(ans, j-i+1);
                sum-=a[i];
                i++;
            }
            
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};