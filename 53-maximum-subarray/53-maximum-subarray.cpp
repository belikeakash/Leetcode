class Solution {
public:
    
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        int best = a[0];
        int sum = a[0];
        for(int i=1;i<n;i++) {
            sum = max(sum+a[i],a[i]);
            best = max(best, sum);
        }
        return best;
    }
};