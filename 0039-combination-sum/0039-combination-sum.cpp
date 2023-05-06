class Solution {
public:
    vector<vector<int>>ans;
    void func(int i, int n, vector<int>&a, int x, vector<int>v) {
        if(x<0) return;
        else if(x==0) {
            ans.push_back(v);
            return;
        }
        for(int j=i;j<n;j++) {
                v.push_back(a[j]);
                func(j,n,a,x-a[j],v);
                v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int x) {
        vector<int>v;
        sort(v.begin(),v.end());
        func(0,a.size(),a,x,v);
        return ans;
    }
};