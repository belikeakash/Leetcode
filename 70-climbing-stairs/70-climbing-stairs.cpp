class Solution {
public:
    vector<int>v;
    int func(vector<int>&v, int n) {
        if(n<=2) return n;
        if(v[n]!=-1) return v[n];
        
        return v[n] = func(v,n-1) + func(v,n-2);
    }
    int climbStairs(int n) {
        v.resize(n+1,-1);
        return func(v,n);
    }
};