class Solution {
public:
    
    int climbStairs(int n) {
        if(n==1) return 1;
        int prev1 = 2;
        int prev2 = 1;
        int ans = 2;
        for(int i=3;i<=n;i++) {
            ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        
        return ans;
    }
};