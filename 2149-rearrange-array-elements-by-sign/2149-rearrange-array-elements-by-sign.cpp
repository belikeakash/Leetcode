class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size();
        vector<int>v(n,0);
        int j = 0;
        for(int i=0;i<n;i++) {
            if(a[i]>0) {
                v[j]=a[i];
                j=j+2;
            }
        }
        j = 1;
        for(int i=0;i<n;i++) {
            if(a[i]<0) {
                v[j]=a[i];
                j=j+2;
            }
        }
        return v;
    }
};