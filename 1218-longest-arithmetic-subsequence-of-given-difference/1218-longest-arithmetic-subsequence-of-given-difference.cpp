class Solution {
public:
    
    int longestSubsequence(vector<int>& a, int d) {
        int n = a.size();
        unordered_map<int, int>m;
        for(int i=0;i<n;i++) {
            if(m.count(a[i]-d)) m[a[i]] = m[a[i]-d] + 1;
            else m[a[i]] = 1;
        }
        int ans = 1;
        for(auto x:m) {
            ans = max(ans, x.second);
        }
        
        return ans;
    }
};