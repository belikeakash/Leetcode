class Solution {
public:
    int ans = INT_MAX;
    void func(int i, vector<int>&a, vector<int>&sum, int k) {
        if(i>=a.size()) {
            int res = 0;
            for(int j=0;j<k;j++) {
                res = max(res, sum[j]);
            }
            ans = min(ans, res);
            return;
        }
        for(int j=0;j<k;j++) {
            sum[j]+=a[i];
            func(i+1, a, sum, k);
            sum[j]-=a[i];
        }
    }
    int distributeCookies(vector<int>& a, int k) {
        vector<int>sum(k,0);
        func(0,a,sum,k);
        
        return ans;
    }
};