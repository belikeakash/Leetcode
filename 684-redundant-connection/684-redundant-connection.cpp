class Solution {
public:
    int flag = -1;
    unordered_set<int>s;
    vector<int>a;
    bool DFS(vector<vector<int>>&ar, vector<int>&vis, int node, int par) {
        vis[node] = 1;
        a.push_back(node);
        for(auto x:ar[node]) {
            if(vis[x]==0) {
                if(DFS(ar,vis,x,node)) return 1;
            }
            else {
                if(par!=x) {
                    a.push_back(x);
                    return 1;
                }
            }
        }
        a.pop_back();
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        vector<vector<int>>ar(v.size()+1);
        for(int i=0;i<v.size();i++) {
            ar[v[i][0]].push_back(v[i][1]);
            ar[v[i][1]].push_back(v[i][0]);
        }
        vector<int>vis(v.size()+1,0);
        DFS(ar,vis,1,-1);
        int u = a[a.size()-1];
        s.insert(u);
        for(int i=a.size()-2;i>=0;i--) {
            if(a[i]==u) break;
            s.insert(a[i]);
        }
        // for(auto x:a) {
        //     s.insert(x);
        // }
        for(int i=v.size()-1;i>=0;i--) {
            if(s.count(v[i][0]) && s.count(v[i][1])) return v[i]; 
        }
        return { };
    }
};