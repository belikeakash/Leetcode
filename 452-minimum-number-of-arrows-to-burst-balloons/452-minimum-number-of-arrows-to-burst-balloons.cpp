class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(),a.end(),cmp);
        int st = a[0][0];
        int en = a[0][1];
        int d = a[0][1];
        int ans = 1;
        for(int i=1;i<n;i++) {
            if(d>=a[i][0]) {
                d = max(a[i][0],d);
            }
            else {
                ans++;
                d = a[i][1];
            }
            
        }
        return ans;
    }
};