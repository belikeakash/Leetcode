class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        if(a[1]==b[1]) return a[0]<b[0];
        else return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), cmp);
        int s = a[0][0], e = a[0][1];
        int cnt = 0;
        for(int i=1;i<n;i++) {
            if(a[i][0]<e) {
                cnt++;
            }
            else {
                s = a[i][0];
                e = a[i][1];
            }
        }
        
        return cnt;
    }
};