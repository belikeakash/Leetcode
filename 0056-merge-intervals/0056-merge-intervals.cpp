class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>>ans;
        int s=a[0][0],e=a[0][1];
        int n = a.size();
        for(int i=1;i<n;i++) {
            if(a[i][0]<=e) {
                e = max(a[i][1],e);
            }
            else {
                ans.push_back({s,e});
                s = a[i][0];
                e = a[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};