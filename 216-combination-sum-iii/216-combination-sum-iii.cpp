class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void func(int i, vector<int>&a, int sum, int k) {
        if(sum==0) {
            if(v.size()==k) ans.push_back(v);
            return;
        }
        if(i==a.size()) return;
        if(sum<0) return;
        if(a[i]<=sum) {
            v.push_back(a[i]);
            func(i+1,a,sum-a[i],k);
            v.pop_back();
            
            func(i+1,a,sum,k);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a(9,0);
        for(int i=0;i<9;i++) a[i]=i+1;
        func(0,a,n,k);
        return ans;
    }
};