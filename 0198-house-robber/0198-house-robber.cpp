class Solution {
public:
    map<pair<int,int>,int>mp;
    int func(int pre, int cur, vector<int>&a) {
        if(cur==a.size()) return 0;
        int ans1 = 0;
        int ans2 = 0;
        if(mp.count({pre,cur})) return mp[{pre,cur}];
        if(pre==-1 || cur-pre>1) {
            ans1 = max(func(pre,cur+1,a),a[cur]+func(cur,cur+1,a));
        }
        else {
            ans2 = func(pre,cur+1,a);
        }
        return mp[{pre,cur}] = max(ans1,ans2);
    }
    int rob(vector<int>& a) {
        int n = a.size();
        return func(-1,0,a);
    }
};