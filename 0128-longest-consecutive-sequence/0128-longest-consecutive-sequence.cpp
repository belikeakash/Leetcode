class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_map<int,int>m,vis;
        int ans = 0;
        for(auto x:a) m[x]++;
        for(auto x:a) {
            if(vis[x]) continue;
            int dis = 1;
            int n1 = x-1;
            vis[x] = 1;
            while(m[n1]) {
                dis++;
                vis[n1]=1;
                n1 = n1-1;
            }
            n1 = x+1;
            while(m[n1]) {
                dis++;
                vis[n1]=1;
                n1 = n1+1;
            }
            
            ans = max(ans,dis);
        }
        return ans;
    }
};