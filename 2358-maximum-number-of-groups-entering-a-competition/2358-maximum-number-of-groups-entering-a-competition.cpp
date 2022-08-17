class Solution {
public:
    int maximumGroups(vector<int>& a) {
        // sort(a.begin(),a.end());
        int n = a.size();
        int ans = 0;
        int i = 0;
        int x=0;
        while(x<=n) {
            ans++;
            i=i+1;
            x = x+i;
        }
        
        if(x==n) return ans;
        else return ans-1;
    }
};