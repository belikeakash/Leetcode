class Solution {
public:
    double func(double x, long long n) {
        if(n==0) return 1;
        double ans = func(x,n/2)    ;
        if(n%2==0) return ans*ans;
        else return x*ans*ans;
    }
    double myPow(double x, long long n) {
        if(n<0) {
            n = -n;
            x = 1/x;
        }
        return func(x,n);
    }
};


