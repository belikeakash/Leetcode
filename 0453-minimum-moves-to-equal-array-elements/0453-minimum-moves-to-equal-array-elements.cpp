class Solution {
public:
    int minMoves(vector<int>& a) {
        sort(a.begin(),a.end());
        int carry = 0;
        int cnt = 0;
        int n = a.size();
        for(int i=1;i<n;i++) {
            if(a[i-1]!=a[i]+carry) {
                cnt+=(a[i]-a[i-1]) + carry;
                carry += a[i]-a[i-1];
            }
        }
        return cnt;
    }
};