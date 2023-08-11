class Solution {
public:
    int numTrees(int n) {
        int ans = 0;
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        for(int i=0;i<=n-1;i++) {
            ans = ans + numTrees(i) * numTrees(n-1-i);
        }
        
        return ans;
    }
};