class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        int n = a.size();
        vector<int>v1(n,0),v2(n,0);
        long long sum = 0;
        for(int i=0;i<n;i++) {
            sum+=1LL*a[i];
            v1[i] = sum/(i+1);
        }
        sum = 0;
        int j = 1;
        for(int i=n-1;i>0;i--) {
            sum+=1LL*a[i];
            v2[i-1] = sum/j;
            j++;
        }
        int mini = INT_MAX;
        int idx = 0;
        for(int i=0;i<n;i++) {
            cout<<abs(v1[i]-v2[i])<<" ";
            if(abs(v1[i]-v2[i])<mini) {
                idx = i;
                mini = abs(v1[i] - v2[i]);
            }
        }
        return idx;
    }
};