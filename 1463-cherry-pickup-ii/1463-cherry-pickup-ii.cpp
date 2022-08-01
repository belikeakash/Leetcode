class Solution {
public:
    vector<vector<vector<int>>>mp;
    int func(int i1,int j1, int j2, int n, int m, vector<vector<int>>& a) {
        if(i1<0 || i1>=n || j1<0 || j2<0 || j1>=m || j2>=m) {
            return 0;
        }
        int c = 0;
        // if(i1==n-1 && i2==n-1) {
        //     if(i1==i2 && j1==j2) {
        //     c+= a[i1][j1];
        // }
        // else {
        //     c+= a[i1][j1] + a[i2][j2];
        // }
        //     return c;
        // }
        // string s = to_string(i1)+"*"+to_string(j1)+"*"+to_string(j2);
        // if(mp.count(s)) {cout<<"a"; return mp[s];}
        if(mp[i1][j1][j2]!=-1) return mp[i1][j1][j2];
        if(j1==j2) {
            c+= a[i1][j1];
        }
        else {
            c+= a[i1][j1] + a[i1][j2];
        }
        // cout<<c<<" ";
        int p1 = func(i1+1,j1,j2,n,m,a);
        int p2 = func(i1+1,j1-1,j2-1,n,m,a);
        int p3 = func(i1+1,j1+1,j2+1,n,m,a);
        int p4 = func(i1+1,j1,j2-1,n,m,a);
        int p5 = func(i1+1,j1,j2+1,n,m,a);
        int p6 = func(i1+1,j1-1,j2,n,m,a);
        int p7 = func(i1+1,j1-1,j2+1,n,m,a);
        int p8 = func(i1+1,j1+1,j2,n,m,a);
        int p9 = func(i1+1,j1+1,j2-1,n,m,a);
        // cout<<c<<" ";
        // cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<" "<<p6<<" "<<p7<<" "<<p8<<" "<<p9<<" "<<c<<endl;
        c += max({p1,p2,p3,p4,p5,p6,p7,p8,p9});
        
        return mp[i1][j1][j2] = c;
    }
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        mp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(0,0,m-1,n,m,a);
    }
};