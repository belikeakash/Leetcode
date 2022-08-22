class Solution {
public:
    vector<int>v;
    vector<vector<int>>ans;
    // set<int>s;
    void func(int i, vector<int>&a) {
        ans.push_back(v);
        for(int j=i;j<a.size();j++) {
            if(i!=j && a[j-1]==a[j]) continue;
            v.push_back(a[j]);
            func(j+1,a);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(),a.end());
        func(0,a);
        return ans;
    }
};