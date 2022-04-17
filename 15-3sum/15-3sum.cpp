class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        int n = a.size();
        for(int i=0;i<n-2;i++) {
            int j = i+1;
            int k = n-1;
            while(j<k) {
                if(a[i]+a[j]+a[k]==0) {
                    s.insert({a[i],a[j],a[k]});
                    j++;
                    k--;
                }
                else if(a[i]+a[j]+a[k]<0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        for(auto x:s) {
            ans.push_back(x);
        }
        return ans;
    }
};