class Solution {
public:
    int wateringPlants(vector<int>& a, int y) {
        int n = a.size();
        int x = y;
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(x-a[i]>=0) {ans++; x=x-a[i];}
            else {
                // if(i==n-1) ans+=i+1;
                ans+=(i+1)+i;
                x = y - a[i];
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};