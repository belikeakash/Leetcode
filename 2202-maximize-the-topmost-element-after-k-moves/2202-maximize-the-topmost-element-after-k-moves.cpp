class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        vector<int>b;
        if(k%2==1 && a.size()==1) return -1;
        if(k==0) return a[0];
        int n= a.size();
        cout<<n<<endl;
        // k = min(n,k);
        int x = k-1;
        int maxi1 = -1;
        int maxi2 = -1;
        int pos = -1;
        int i=0;
        while(x-- && i<n) {
            if(maxi1<a[i]) {
                maxi2 = maxi1;
                maxi1 = a[i];
                pos = i;
            }
            else if(maxi2<a[i]) maxi2 = a[i];
            i++;
        }
        cout<<maxi1<<" "<<maxi2<<" "<<pos<<endl;
        int ans = -1;
        if(k-n>0) ans = maxi1;
        else if(k-n==0) {
            if(pos!=n-1) ans = maxi1;
            else ans = maxi2;}
        else {
            cout<<"b";
            if(i+1<n) ans = max(a[i+1],maxi1);
            else{cout<<"a"; ans = maxi2; }
        }
        return ans;
    }
};