class Solution {
public:
    
    int minJumps(vector<int>& a) {
        int n = a.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++) {
            m[a[i]].push_back(i);
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(0);
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto x = q.front();
                vis[x]=1;
                if(x==n-1) return ans;
                q.pop();
                vector<int>&v = m[a[x]];
                v.push_back(x-1);
                v.push_back(x+1);
                for(auto y:v) {
                    if(y>=0 && y<n && vis[y]==0) q.push(y);
                }
                v.clear();
            }
            ans++;
            
        }
        return ans;
    }
};