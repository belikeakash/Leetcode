class Solution {
public:
    int numTimesAllBlue(vector<int>& a) {
        set<int>s;
        int n = a.size();
        int maxi = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            s.insert(a[i]);
            maxi = max(maxi,a[i]);
            if(maxi==i+1) ans++;
        }
        return ans;
    }
};