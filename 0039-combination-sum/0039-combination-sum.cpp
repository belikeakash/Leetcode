class Solution {
public:
    vector<vector<int>>ans;
    void func(int i, int n, vector<int>&a, int x, vector<int>v) {
        if(x<0) return;
        else if(x==0) {
            ans.push_back(v);
            return;
        }
        if(i>=n) return;
        v.push_back(a[i]);
        func(i,n,a,x-a[i],v);
        v.pop_back();
        func(i+1,n,a,x,v);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int x) {
        vector<int>v;
        sort(v.begin(),v.end());
        func(0,a.size(),a,x,v);
        return ans;
    }
};