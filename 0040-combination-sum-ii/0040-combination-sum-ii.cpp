class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    void func(int i, int n, vector<int>&a, int x, vector<int>v) {
        if(x<0) return;
        else if(x==0) {
            ans.push_back(v);
            return;
        }
        if(i>=n) return;
        for(int j=i;j<n;j++) {
            if(j>i && a[j]==a[j-1]) continue;
            v.push_back(a[j]);
            func(j+1,n,a,x-a[j],v);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int x) {
        vector<int>v;
        sort(a.begin(),a.end());
        func(0,a.size(),a,x,v);
        return ans;
    }
};