class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& a) {
        int n = a.size();
        bool flag = 0;
        for(int i=1;i<n;i++) {
            if(a[i]<a[i-1]) {flag=1; break;}
        }
        if(flag==0) return a;
        else {
            int pos = n-1;
            for(int i=n-1;i>=1;i--) {
                if(a[i-1]>a[i]) {pos = i-1; break;}
                
            }
            int pos2 = pos+1;
            int maxi = INT_MIN;
            for(int i=pos+1;i<n;i++) {
                if(a[i]>maxi && a[i]<a[pos]) {
                    maxi = a[i];
                    pos2 = i;
                }
            }
            swap(a[pos],a[pos2]);
            return a;
        }
    }
};