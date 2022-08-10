class Solution {
public:
    int numRescueBoats(vector<int>& a, int x) {
        int n = a.size();
        if(n==1) return 1;
        sort(a.begin(),a.end());
        int i = 0,j=n-1;
        int ans = 0;
        int p = x;
        int f =0;
        while(i<=j) {
            p = p - a[j];
            j--;
            while(f==0 && j>=0 && p-a[j]>=0 && j>=i) {
                p = p-a[j];
                j--;
                f = 1;
            }
            while(f==0 && j>=i && p-a[i]>=0) {
                p = p - a[i];
                i++;
                f = 1;
            }
            ans++;
            p = x;
            f = 0;
        }
        return ans;
    }
};