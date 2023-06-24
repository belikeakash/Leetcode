class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int x) {
        int c = 0;
        int n = a.size();
        if(x==0) return 1;
        if(n==1) {
            if(a[0]==0) {
                return 1;
            }
            return 0;
        }
        int j=0;
        for(int i=0;i<n;i++) {
            if(a[i]==1) {
                break;
            }
            else {
                c++;
            }
            j++;
        }
        if(c==n) return (c+1)/2>=x;
        int u = (c)/2;
        x-=u;
        c = 0;
        for(int i=j;i<n;i++) {
            if(a[i]==1) {
                int u = (c-1)/2;
                x-=u;
                c = 0;
            }
            else {
                c++;
            }
        }
        
        if(a[n-1]==0) {
            int u = (c)/2;
            x-=u;
            c = 0;
        }
        return x<=0;
    }
};