class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n = a.size();
        int i = 0;
        int j = 0;
        int prod = 1;
        int ans = 0;
        while(j<n) {
            prod = prod*a[j];
            while(i<=j && prod>=k) {
                prod = prod/a[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        
        return ans;
    }
};