class Solution {
public:
    int fourSumCount(vector<int>& a1, vector<int>& a2, vector<int>& a3, vector<int>& a4) {
        int n = a1.size();
        unordered_map<int,int>m;
        for(auto x:a1) {
            for(auto y:a2) {
                m[x+y]++;
            }
        }
        int ans = 0;
        for(auto x:a3) {
            for(auto y:a4) {
                ans+=m[-x-y];
            }
        }
        return ans;
    }
};