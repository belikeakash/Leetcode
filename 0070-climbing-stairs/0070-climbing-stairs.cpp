class Solution {
public:
    unordered_map<int,int>mp;
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        if(mp[n]) return mp[n];
        return mp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};