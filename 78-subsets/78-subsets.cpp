class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    void func(int i, vector<int>&a) {
        if(i==a.size()) {
            ans.push_back(v);
            return;
        }
        func(i+1,a);
        v.push_back(a[i]);
        func(i+1,a);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& a) {
        func(0,a);
        return ans;
    }
};