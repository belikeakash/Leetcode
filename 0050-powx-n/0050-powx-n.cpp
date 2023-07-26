class Solution {
public:
    double myPow(double x, long long n) {
        if(n<0) return myPow(1/x, -n);
        if(n==0) return 1;
        double ans = myPow(x,n/2);
        if(n%2!=0) return x*ans*ans;
        return ans*ans;
    }
};