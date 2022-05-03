class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        int n = a.size();
        int sum = 0;
        for(int i=0;i<k;i++) {
            sum+=a[i];
        }
        int maxi = sum;
        int j = 0;
        for(int i=k;i<n;i++) {
            sum+=a[i]-a[j];
            j++;
            maxi = max(maxi,sum);
        }
        double ans = (double)maxi/(double)k;
        return ans;
    }
};