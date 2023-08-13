class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        set<pair<int,int>>s;
        int n = a.size();
        sort(a.begin(), a.end());
        unordered_map<int, int>m;
        for(int i=0;i<n;i++) {
            if(m[a[i]-k]) s.insert({a[i], a[i]-k});
            m[a[i]] = 1;
        }
        
        return s.size();
    }
};