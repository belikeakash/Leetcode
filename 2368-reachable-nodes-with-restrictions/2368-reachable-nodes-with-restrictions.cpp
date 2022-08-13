class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& e, vector<int>& b) {
        vector<vector<int>>ar(n);
        for(auto x:e) {
            ar[x[0]].push_back(x[1]);
            ar[x[1]].push_back(x[0]);
        }
        unordered_map<int,int>m;
        vector<int>vis(n,0);
        for(auto x:b) m[x]=1;
        int ans = 0;
        for(int i=0;i<1;i++) {
            if(vis[i]==0 && m[i]!=1) {
                cout<<i<<" ";
                queue<int>q;
                q.push(i);
                // ans++;
                vis[i]=1;
                while(!q.empty()) {
                    int n = q.size();
                    for(int j=0;j<n;j++) {
                        int x = q.front();
                        vis[x]=1;
                        
                        q.pop();
                        if(m[x]!=1) {
                            ans++;
                            // cout<<x<<" ";
                            for(auto p:ar[x]) {
                                if(vis[p]==0 && m[x]!=1) {
                                    // vis[p]=1;
                                    q.push(p);
                                }
                            }
                        }
                        
                    }
                }
            }
        }
        return ans;
    }
};