class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        int n = a.size();
        vector<int>b(n,0);
        for(int i=0;i<n;i++) {
            b[i] = a[i];
        }
        sort(a.begin(),a.end());
        vector<int>ans(n,0);
        map<int,int>m;
        for(int i=n-1;i>=0;i--) m[a[i]] = i;
        for(int i=0;i<n;i++) {
            ans[i] = m[b[i]];
        }
        return ans;
    }
};