class Solution {
public:
    set<vector<int>>s;
    void func(int i, int n, vector<int>&a,vector<int>v) {
        if(i==n) {
            s.insert(v);
            return;
        }
        func(i+1,n,a,v);
        v.push_back(a[i]);
        func(i+1,n,a,v);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<int>v;
        sort(a.begin(),a.end());
        func(0,a.size(),a,v);
        
        vector<vector<int>>ans;
        for(auto x:s) {
            ans.push_back(x);
        }
        return ans;
    }
};