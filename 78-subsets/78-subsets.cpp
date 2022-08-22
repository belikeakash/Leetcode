class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    void func(int i, vector<int>&a) {
        ans.push_back(v);
        for(int j=i;j<a.size();j++) {
            v.push_back(a[j]);
            func(j+1,a);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& a) {
        func(0,a);
        return ans;
    }
};