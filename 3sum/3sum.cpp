class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>>ans;
        int n = a.size();
        set<vector<int>>s;
        sort(a.begin(),a.end());
        for(int i=0;i<n-2;i++) {
            int l = i+1;
            int r = n-1;
            while(l<r) {
                if(a[i]+a[l]+a[r]==0) {
                    s.insert({a[i],a[l],a[r]});
                    // ans.push_back({a[i],a[l],a[r]});
                    l++;
                    r--;
                }
                else if(a[i]+a[l]+a[r] < 0) {
                    l++;
                }
                else r--;
            }
        }
        for(auto x:s) {
            ans.push_back(x);
        }
        return ans;
    }
};