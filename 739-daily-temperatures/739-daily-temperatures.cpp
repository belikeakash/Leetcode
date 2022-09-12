class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<pair<int,int>>s;
        int n = a.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++) {
            while(s.size() && a[i]>s.top().first) {
                ans[s.top().second] = i-s.top().second;
                s.pop();
            }
            s.push({a[i],i});
        }
        return ans;
    }
};