class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void func(int i, vector<int>&a, int sum) {
        
        if(sum==0) {ans.push_back(v); return;}
        if(i>=a.size() || i<0) return ;
        if(sum<0) return ;
        func(i+1,a,sum);
        v.push_back(a[i]);
        func(i,a,sum-a[i]);
        v.pop_back();
        // return func(i+1,a,sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        func(0,a,target);
        sort(a.begin(),a.end());
        return ans;
    }
};