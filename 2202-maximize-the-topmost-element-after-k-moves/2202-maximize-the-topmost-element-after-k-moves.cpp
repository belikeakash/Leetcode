class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        // int x= -1;
        if(k%2==1 && a.size()==1) return -1;
        // else if(k>a.size() && a.size()==1) return -1;
        int maxi = -1,maxp=-1;
        for(int i=0;i<a.size();i++) {
            if(a[i]>maxi){
                maxi = a[i];
                maxp = i;
            }
        }
        cout<<maxp<<" ";
        if(maxp==k) {cout<<"maxi"; return maxi;}
        int x1 = -1,x2 = -1;
        int n = a.size();
        int f = min(k-1,n);
        for(int i=0;i<f;i++) {
            if(x1==-1) x1 = a[i];
            else {
                if(a[i]>x1) {
                    x2 = x1;
                    x1 = a[i];
                }
                else if(a[i]>x2) {
                    x2 = a[i];
                }
            }
        }
        if(k==1) return a[1];
        if(k<n) return max(x1,a[k]);
        else return x1;
    }
};