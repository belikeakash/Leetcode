class Solution {
public:
    bool isPossibleDivide(vector<int>& a, int k) {
        unordered_map<int,int>m;
        for(auto x:a) {
            m[x]++;
        }
        sort(a.begin(),a.end());
        int x = a[0];
        int y = 0;
        int ans = 0;
        int z = -1;
        while(1) {
            cout<<x<<" ";
            if(m[x]==1) {
                m[x]--;
                x++;
                y++;
            }
            else if(m[x]>1) {
                m[x]--;
                
                y++;
                if(z==-1) {
                    z = x;
                }
                x++;
            }
            else {cout<<"a"; return 0;}
            if(y==k) {
                ans++;
                if(ans*k>=a.size()) break;
                if(z==-1) {x = a[ans*k]; z = -1;}
                else {x = z; z=-1;}
                y = 0;
            }
            if(ans*k>=a.size()) break;
            // cout<<y<<" ";
        }
        if(y==0 || y==k) return 1;
        return 0;
    }
};