class Solution {
public:
    int findPoisonedDuration(vector<int>& a, int t) {
        int n = a.size();
        int ans=0,pre=0;
        for(int i=0;i<n;i++) {
            if(pre>a[i]) ans=ans-(pre-a[i]);
            pre = a[i] + t ;
            ans+=t;
        }
        return ans;
    }
};