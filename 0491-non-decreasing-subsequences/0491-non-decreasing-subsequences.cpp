class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    void func(int prev, int i, vector<int>&a, vector<int>&v) {
        if(i>=a.size()) {
           if(v.size()>1) s.insert(v);
            //if(v.size()>1)ans.push_back(v);
            return;}
        if(prev==-1 || a[i]>=a[prev]) {
            v.push_back(a[i]);
            func(i, i+1, a, v);
            v.pop_back();
            //func(prev, i+1, a, v);
        }
        func(prev, i+1, a, v);
    }
    vector<vector<int>> findSubsequences(vector<int>& a) {
        vector<int>v;
        func(-1, 0, a, v);
        for(auto x:s) ans.push_back(x);
        return ans;
    }
};