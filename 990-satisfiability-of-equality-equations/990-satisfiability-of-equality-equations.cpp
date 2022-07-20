class Solution {
public:
    void DFS(int node, vector<vector<int>>&ar, int c, vector<int>&vis, vector<int>&color) {
        vis[node] = 1;
        color[node] = c;
        cout<<c<<" "<<node<<endl;
        for(auto x:ar[node]) {
            if(vis[x]==0) {
                DFS(x,ar,c,vis,color);
            }
        }
    }
    bool equationsPossible(vector<string>& v) {
        vector<vector<int>>ar(26);
        vector<int>color(26);
        vector<int>vis(26);
        
        for(auto x:v) {
            if(x[1]=='=') {
                ar[x[0]-'a'].push_back(x[3]-'a');
                ar[x[3]-'a'].push_back(x[0]-'a');
            }
        }
        int c = 0;
        for(int i=0;i<26;i++) {
            if(vis[i]==0) DFS(i,ar,c,vis,color);
            c++;
        }
        for(auto x:v) {
            if(x[1]=='!') {
                if(color[x[0]-'a']==color[x[3]-'a']) return 0;
            }
        }
        return 1;
    }
};