class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    vector<int>v;
    void func(int i, vector<int>&a, int sum) {
        if(sum==0) {ans.push_back(v); return;}
        if(sum<0) return;
        if(i==a.size()) return;
        
        for(int j=i;j<a.size();j++) {
            if(a[j]>sum) break;
            if(j>i && a[j]==a[j-1]) continue;
            v.push_back(a[j]);
            func(j+1,a,sum-a[j]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        func(0,a,target);
        for(auto x:s) ans.push_back(x);
        return ans;
    }
};