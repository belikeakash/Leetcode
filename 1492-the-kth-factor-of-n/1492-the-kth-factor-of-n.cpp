class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i=1;i<=n/2;i++) {
            if(n%i==0) {
                if(k==1) return i;
                else k--;
            }
        }
        if(k==1) return n;
        return -1;
    }
};