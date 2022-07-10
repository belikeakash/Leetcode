class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        int n = a.size();
        vector<int>ans;
        for(int i=0;i<n;i++) {
            int l = i+1,r=n-1;
            while(l<=r) {
                int mid = l+(r-l)/2;
                if(a[i]+a[mid]==x) {
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    return ans;
                }
                else if(a[i]+a[mid]<x) {
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
        }
        return ans;
    }
};