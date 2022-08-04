class Solution {
public:
    
    int jump(vector<int>& a) {
        int n = a.size();
        int s = 0,e=0,ans=0,maxi=0;
        
        while(e<n-1) {
            ans++;
            for(int i=s;i<=e;i++) {
                maxi = max(maxi,i+a[i]);
                if(maxi>=n-1) return ans;
            }
            s = e+1;
            e = maxi;
        }
        return ans;
    }
};