class Solution {
public:
    void func(int idx, vector<int>&a, vector<vector<int>>&ans) {
        if(idx==a.size()) {
            ans.push_back(a);
            return;
        }
        for(int i=idx;i<a.size();i++) {
            swap(a[i], a[idx]);
            func(idx+1, a, ans);
            swap(a[i], a[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>>ans;
        func(0, a, ans);
        
        return ans;
    }
};