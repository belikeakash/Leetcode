class Solution {
public:
    void func(int idx, vector<int>&a, vector<vector<int>>&ans) {
        if(idx==a.size()) {
            ans.push_back(a);
            return;
        }
        set<int>s;
        for(int i=idx;i<a.size();i++) {
            if(s.count(a[i])) continue;
            swap(a[i], a[idx]);
            func(idx+1, a, ans);
            swap(a[i], a[idx]);
            s.insert(a[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>>ans;
        func(0, a, ans);
        
        return ans;
    }
};