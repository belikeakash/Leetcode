class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        queue<pair<int,int>>q;
        for(int i=0;i<a.size();i++) {
            for(int j=0;j<a.size();j++) {
                if(a[i][j]==1) {
                    q.push({i,j});
                }
            }
        }
        int res = 0;
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            vector<pair<int,int>>dir {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto y:dir) {
                int i = x.first + y.first;
                int j = x.second + y.second;
                
                if(i>=0 && i<a.size() && j>=0 && j<a.size() && a[i][j]==0) {
                    a[i][j] = a[x.first][x.second] + 1;
                    q.push({i,j});
                    res = max(res,a[i][j]);
                }
            }
        }
        return res - 1;
    }
};