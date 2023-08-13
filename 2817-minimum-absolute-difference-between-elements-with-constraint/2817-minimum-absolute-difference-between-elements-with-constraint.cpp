class Solution {
public:
    int minAbsoluteDifference(vector<int>& a, int x) {
        set<int>s;
        int ans = INT_MAX;
        int n = a.size();
        for(int i=n-x-1;i>=0;i--) {
            s.insert(a[i+x]);
            auto c = s.lower_bound(a[i]);
            if(c!=s.end()) {
                ans = min(ans, abs(a[i]-*c));
            }
            if(c!=s.begin()) {
                ans = min(ans, abs(a[i]-*prev(c)));
            }
        }
        
        return ans;
    }
};