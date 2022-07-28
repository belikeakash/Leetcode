class Solution {
public:
    int ans = 0;
    int func(int i, vector<int>&a, int x, int sum) {
        if(i==a.size()) {
            if(sum==x) return 1;
            else return 0;
        }
        return func(i+1,a,x,sum+a[i]) + func(i+1,a,x,sum);
    }
    int findTargetSumWays(vector<int>& a, int target) {
        int sum = 0;
        for(auto x:a) sum+=x;
        int x = sum-target;
        cout<<x<<" ";
        if(x%2!=0) return 0;
        return func(0,a,x/2,0);
        // return ans;
    }
};