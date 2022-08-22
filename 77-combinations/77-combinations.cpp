class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void func(int i, int n, int k) {
        if(v.size()==k) {
            ans.push_back(v);
            return;
        }
        for(int j=i;j<=n;j++) {
            v.push_back(j);
            func(j+1,n,k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        int i = 1;
        func(i,n,k);
        return ans;
    }
};