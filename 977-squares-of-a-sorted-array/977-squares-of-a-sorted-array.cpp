class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        multiset<int>v;
        int n = a.size();
        for(auto x:a) v.insert(abs(x));
        vector<int>ans;
        for(auto x:v) {
            ans.push_back(x*x);
        }
        return ans;
    }
};