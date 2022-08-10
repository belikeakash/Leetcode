class Solution {
public:
    int robotSim(vector<int>& a, vector<vector<int>>& b) {
        map<vector<int>,int>m;
        for(auto x:b) {
            m[x] = 1;
        }
        int ans = 0;
        int x = 0;
        int y = 0;
        int n = a.size();
        int l = 0;
        for(int i=0;i<n;i++) {
            if(a[i]==-1) l=l+1;
            else if(a[i]==-2) l=l-1;
            else {
                l = l%4;
            if(l==0) {
                while(a[i]!=0) {
                    y+=1;
                    a[i]--;
                    if(m[{x,y}]==1) {a[i]=0; y--;}
                }
            }
            if(l==1 || l==-3) {
                while(a[i]!=0) {
                    x+=1;
                    a[i]--;
                    if(m[{x,y}]==1) {a[i]=0; x--;}
                }
            }
            if(l==-1 || l==3) {
                while(a[i]!=0) {
                    x-=1;
                    a[i]--;
                    if(m[{x,y}]==1) {a[i]=0; x++;}
                }
            }
            if(l==2 || l==-2) {
                while(a[i]!=0) {
                    y-=1;
                    a[i]--;
                    if(m[{x,y}]==1) {a[i]=0; y++;}
                }
            }
                cout<<x<<" "<<y<<endl;
                ans = max(ans,(x*x) + (y*y));
            }
            
        }
        
        return ans;
    }
};