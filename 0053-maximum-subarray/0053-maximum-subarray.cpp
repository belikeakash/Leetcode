class Solution {
public:
    int ans = 0;
    unordered_map<int,int>m;
    int func(int i, vector<int>&a) {
        if(i>=a.size()) return 0;
        if(m.count(i)) return m[i];
        int ans1 = a[i] + func(i+1,a);
        int ans2 = a[i];
        int c = max({ans1,ans2});
        ans = max(c,ans);
        return m[i] = c;
    }
    int maxSubArray(vector<int>& a) {
        ans = a[0];
        func(0,a);
        
        return ans;
    }
};