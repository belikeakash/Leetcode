class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        unordered_map<int,vector<int>>m;
        for(auto x:a) {
            m[x[0]].push_back(x[1]);
        }
        int ans = 0;
        ans+=(n-m.size())*2;
        for(auto y:m) {
            bool flag = 0;
            vector<int>vis(11,0);
            for(auto x:y.second) {
                vis[x]=1;
            }
            if(!vis[2] && !vis[3] && !vis[4] && !vis[5]) {
                ans++;
                flag = 1;
            }
            if(!vis[9] && !vis[6] && !vis[7] && !vis[8]) {
                ans++;
                flag = 1;
            }
            if(!flag && !vis[4] && !vis[5] && !vis[6] && !vis[7]) {
                ans++;
            
        }
    }
        return ans;
    }
};