class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int prod = 0;
        int ans = INT_MIN;
        for(int i=0;i<n;i++) {
            if(a[i]==0) {
                ans = max({ans, 0, prod});
                prod = 0;
            }
            
            else {
                if(prod==0) prod = a[i];
                else prod = prod*a[i];
                ans = max(ans, prod);
            }
        }
        prod = 0;
        for(int i=n-1;i>=0;i--) {
            if(a[i]==0) {
                ans = max({ans, 0, prod});
                prod = 0;
            }
            else {
                if(prod==0) prod = a[i];
                else prod = prod*a[i];
                ans = max(ans, prod);
            }
        }
        
        return ans;
    }
};