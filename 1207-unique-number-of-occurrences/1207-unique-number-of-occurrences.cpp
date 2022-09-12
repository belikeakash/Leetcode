class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        unordered_map<int,int>m,u;
        for(auto x:a) m[x]++;
        for(auto x:m) u[x.second]++;
        for(auto x:u) {
            if(x.second>1) return 0; 
        }
        return 1;
    }
};