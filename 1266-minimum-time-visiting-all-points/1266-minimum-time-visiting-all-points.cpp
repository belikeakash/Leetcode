class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& a) {
        int n = a.size();
        int ans = 0;
        for(int i=1;i<n;i++) {
            
                int p = abs(a[i][0]-a[i-1][0]);
                int q = abs(a[i][1]-a[i-1][1]);
                int r = max(p,q);
                ans+=r;

        }
        return ans;
    }
};