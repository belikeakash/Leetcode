class Solution {
public:
    int ans = 0;
    unordered_map<string,int>m;
    int func(int i1, int j1, int i2, int n, vector<vector<int>>&a) {
        int j2 = i1+j1-i2;
        if(i1>=n || i2>=n || j1>=n || j2>=n || a[i1][j1]==-1 || a[i2][j2]==-1) return INT_MIN;
        if(i1==n-1 && j1==n-1) {
            return a[i1][i2];
        }
        string s = to_string(i1)+"*"+to_string(i2)+"*"+to_string(j1)+"*"+to_string(j2);
        int c = 0;
        if(m.count(s)) return m[s];
        if(i1==i2 && j1==j2) {
            c += a[i1][j1];
        }
        else {
            c += a[i1][j1] + a[i2][j2];
        }
        int p1 = func(i1+1,j1,i2+1,n,a);
        int p2 = func(i1,j1+1,i2+1,n,a);
        int p3 = func(i1+1,j1,i2,n,a);
        int p4 = func(i1,j1+1,i2,n,a);
        // cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<c<<endl;
        c += max({p1,p2,p3,p4});
        cout<<c<<" ";
        return m[s] = c;
    }
    
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size();
        
        return max(0,func(0,0,0,n,a));
    }
};