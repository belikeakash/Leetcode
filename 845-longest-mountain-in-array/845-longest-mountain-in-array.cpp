class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for(int i=1;i<n-1;i++) {
            if(a[i]>a[i-1] && a[i]>a[i+1]) {
                int l = i-1;
                int x = 1;
                while(l>0 && a[l-1]<a[l]) {
                    x++;
                    l--;
                }
                int r = i+1;
                int y = 1;
                while(r<n-1 && a[r+1]<a[r]) {
                    y++;
                    r++;
                }
                
                ans = max(ans,x+y+1);
                i=r;
            }
        }
        return ans;
    }
};