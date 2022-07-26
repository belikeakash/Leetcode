class Solution {
public:
    map<pair<int,int>,bool>m;
    bool func(int x, int y, vector<int>&a) {
        if(y==0) return 0;
        if(x+y==a[a.size()-1]) return 1;
        if(x+y>a[a.size()-1]) return 0;
        if(m.count({x,y})>0) return m[{x,y}];
        bool ans = 0;
        for(int i=0;i<a.size();i++) {
            if(x+y==a[i]) {
                ans = ans || func(a[i],y-1,a) || func(a[i],y,a) || func(a[i],y+1,a);
            }
        }
        return m[{x,y}] = ans;
    }
    bool canCross(vector<int>& a) {
        return func(a[0],1,a);
    }
};