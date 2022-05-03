class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int x) {
        int n = a.size();
        int sum = 0;
        for(int i=0;i<k;i++) {
            sum+=a[i];
        }
        int cnt = 0;
        int avg = sum/k;
        cout<<avg<<" ";
        if(avg>=x) cnt++;
        int j = 0;
        for(int i=k;i<n;i++) {
            sum+=a[i];
            sum-=a[j];
            j++;
            avg = sum/k;
            cout<<sum<<" ";
            if(avg>=x) cnt++;
        }
        return cnt;
    }
};