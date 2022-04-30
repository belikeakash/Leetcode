class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        int n = a.size();
        vector<int>b(101,0);
        for(int i=0;i<n;i++) b[a[i]]++;
        for(int i=1;i<101;i++) b[i] += b[i-1];
        for(int i=0;i<n;i++) {
            if(a[i]==0) a[i] = 0;
            else a[i] = b[a[i]-1];
        }
        return a;
    }
};