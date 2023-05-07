class Solution {
public:
    vector<vector<int>>ans;
    void func(int i, vector<int>&a, vector<int>v) {
        if(i==a.size()) {
            ans.push_back(a);
            return;
        }
        for(int j=i;j<a.size();j++) {
            swap(a[i],a[j]);
            func(i+1,a,v);
            swap(a[i],a[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        vector<int>v;
        func(0,a,v);
        return ans;
    }
};