class Solution {
public:
    int findRadius(vector<int>& a, vector<int>& b) {
        long n = a.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long l = 0,r=10000000009;
        cout<<endl;
        long long ans = -1;
        while(l<r) {
            long long mid = l+(r-l)/2;
            int i = 0,j=0,p=0;
            while(i<a.size() && j<b.size()) {
                int x = b[j] - mid ;
                int y = b[j] + mid ;
                if(a[i]>=x && a[i]<=y) {
                    i++;
                    p++;
                }
                else {
                    j++;
                }
            }
            if(p<n) {
                l = mid + 1;
            }
            else {
                ans = mid;
                r = mid;
            }
        }
        return l;
    }
};