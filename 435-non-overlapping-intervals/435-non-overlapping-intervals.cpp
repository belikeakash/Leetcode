class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        if(a[1]==b[1]) return a[0]<b[0];
        else return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),cmp);
        int ans = 0;
        int st = a[0][0];
        int en = a[0][1];
        int n = a.size();
        for(int i=1;i<n;i++) {
            if(a[i][0]<en) {
                ans++;
            }
            else {
                st = a[i][0];
                en = a[i][1];
            }
        }
        return ans;
    }
};