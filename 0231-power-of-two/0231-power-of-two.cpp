class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return 1;
        else if(n%2!=0 || n<=0) return 0;
        return isPowerOfTwo(n/2);
    }
};