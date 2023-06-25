class Solution {
public:
    int equalPairs(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        map<vector<int>, int>mp;
        for(int i=0;i<n;i++) {
            mp[v[i]]++;
        }
        int ans = 0;
        for(int i=0;i<m;i++) {
            vector<int>c;
            for(int j=0;j<n;j++) {
                c.push_back(v[j][i]);
            }
            // for(auto x:c) cout<<x<<" ";
            // cout<<endl;
            if(mp.count(c)) ans+=mp[c];
        }
        
        return ans;
    }
};