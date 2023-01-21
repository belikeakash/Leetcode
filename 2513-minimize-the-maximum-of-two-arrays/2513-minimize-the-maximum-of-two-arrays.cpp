class Solution {
public:
    int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(long long a, long long b)
{
    long long cc = (a / gcd(a, b)) * b;
    return cc>INT_MAX? INT_MAX : cc;
}
    int func(int x, int d1, int d2, int cnt1, int cnt2) {
        int xcnt1=0,xcnt2=0,xcnt3=0;
        xcnt1 = x - x/d1;
        xcnt2 = x - x/d2;
        int xlcm = lcm(d1,d2);
        
        if(xcnt1>=cnt1 && xcnt2>=cnt2 && (x- x/xlcm)>=cnt1+cnt2) return 1;
        return 0;
        
    }
    int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        int l = cnt1+cnt2;
        int r = INT_MAX;
        int ans = -1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            // cout<<mid<<" ";
            if(func(mid,d1,d2,cnt1,cnt2)) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        cout<<endl;
        return ans;
    }
};