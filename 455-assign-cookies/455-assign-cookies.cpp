class Solution {
public:
    int findContentChildren(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int ans = 0;
        int n  = min(a.size(),b.size());
        int i = 0,j=0;
        while(i<a.size() && j<b.size()) {
            if(b[j]>=a[i]) {
                ans++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};