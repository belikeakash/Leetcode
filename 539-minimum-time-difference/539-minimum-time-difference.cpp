class Solution {
public:
    int findMinDifference(vector<string>& a) {
        vector<int>ans;
        for(auto s:a) {
            int x = stoi(s.substr(0,2));
            int y = stoi(s.substr(3,2));
            int p = x*60 + y;
            ans.push_back(p);
            if(p<720) ans.push_back(p+1440);
        }
        sort(ans.begin(),ans.end());
        int cur = INT_MAX;
        for(int i=1;i<ans.size();i++) {
            cur = min(cur,ans[i]-ans[i-1]);
        }
        return cur;
    }
};