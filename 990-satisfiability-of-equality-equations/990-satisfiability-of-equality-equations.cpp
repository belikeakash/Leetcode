class Solution {
public:
    bool DFS(unordered_map<char,vector<char>>&m, char node, char t,unordered_map<char,int>&vis) {
        vis[node] = 1;
        bool ans = 0;
        for(auto x:m[node]) {
            
            if(vis[x]==0) {
                cout<<x<<" ";
                if(x==t) return 1;
                ans = ans || DFS(m,x,t,vis);
            }
        }
        
        return ans;
    }
    bool equationsPossible(vector<string>& v) {
        int n = v.size();
        vector<vector<int>>ar(n);
        unordered_map<char,vector<char>>m;
        for(auto x:v) {
            string s = x;
            // cout<<s<<" ";
            if(s[1]=='=') {
                m[s[0]].push_back(s[3]);
                m[s[3]].push_back(s[0]);
            }
        }
        unordered_map<char,int>vis;
        for(auto x:v) {
            string s = x;
            if(s[1]=='!') {
                if(s[0]==s[3]) return 0;
                vis.clear();
                cout<<s[0]<<" "<<s[3]<<" ";
                if(DFS(m,s[0],s[3],vis)) return 0;
            }
        }
        return 1;
    }
};