class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    int func(int i, vector<int>&a, int sum) {
        
        if(sum==0) {ans.push_back(v); return 1;}
        if(i>=a.size() || i<0) return 0;
        if(sum<0) return 0;
        if(a[i]<=sum) {
            v.push_back(a[i]);
            func(i,a,sum-a[i]); v.pop_back();
        }
        return func(i+1,a,sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        func(0,a,target);
        sort(a.begin(),a.end());
        return ans;
    }
};