class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int cnt = 0;
        int pro = 1;
        int n = a.size();
        vector<int>ans(n,0);
        for(auto x:a) {
            if(x==0) cnt++;
            else pro*=x;
        }
        if(cnt>1) return ans;
        if(cnt==1) {
            for(int i=0;i<n;i++) {
            if(a[i]==0) {
                ans[i] = pro;
            }
        }
        }
        else {
            for(int i=0;i<n;i++) ans[i] = pro/a[i];
        }
        return ans;
        
    }
};