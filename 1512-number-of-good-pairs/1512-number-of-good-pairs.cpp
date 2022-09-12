class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        unordered_map<int,int>m;
        for(auto x:a) m[x]++;
        int ans = 0;
        for(auto x:m) {
            ans+=(x.second*(x.second - 1))/2;
        }
        return ans;
    }
};