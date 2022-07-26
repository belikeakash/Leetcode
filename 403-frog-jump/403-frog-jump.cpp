class Solution {
public:
    vector<vector<int>>m;
    bool func(int x, int y, vector<int>&a) {
        if(y<=0) return 0;
        if(a[x]+y==a[a.size()-1]) return 1;
        if(a[x]+y>a[a.size()-1]) return 0;
        if(m[x][y]!=-1) return m[x][y];
        bool ans = 0;
        for(int i=0;i<a.size();i++) {
            if(a[x]+y==a[i]) {
                ans = ans || func(i,y-1,a) || func(i,y,a) || func(i,y+1,a);
            }
        }
        return m[x][y] = ans;
    }
    bool canCross(vector<int>& a) {
        m.resize(a.size()+2,vector<int>(a.size()+2,-1));
        return func(a[0],1,a);
    }
};