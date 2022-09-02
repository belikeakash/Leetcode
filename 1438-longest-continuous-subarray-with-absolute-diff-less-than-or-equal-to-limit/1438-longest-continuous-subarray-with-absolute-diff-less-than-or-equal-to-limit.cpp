class Solution {
public:
    int longestSubarray(vector<int>& a, int x) {
        int n = a.size();
        int i = 0,j=0;
        multiset<int>s;
        int ans = 0;
        while(j<n) {
            s.insert(a[j]);
            int p1 = *s.begin();
            int p2 = *s.rbegin();
            if(p2-p1<=x) {
                ans = max(ans,j-i+1);
            }
            else {
                s.erase(s.find(a[i]));
                i++;
            }
            j++;
        }
        return ans;
    }
};