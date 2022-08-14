class Solution {
public:
    vector<vector<int>>ans;
    void func(int i, int n, vector<int>a) {
        if(i==n-1) {ans.push_back(a); return;}
        for(int j=i;j<n;j++) {
            swap(a[i],a[j]);
            func(i+1,n,a);
            swap(a[i],a[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        
        int n = a.size();
        func(0,n,a);
        return ans;
    }
};