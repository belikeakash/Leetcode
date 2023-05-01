class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int j = n-1;
        while(j>0) {
            if(a[j]>a[j-1]) {
                break;
            }
            else {
                j--;
            }
        }
        int i = j;
        cout<<i<<" ";
        for(int x=n-1;x>=i;x--) {
            if(j-1>=0 && a[x]>a[j-1]) {
                swap(a[x],a[j-1]);
                cout<<"a"<<" ";
                break;
            }
        }
        cout<<i<<endl;
        for(int x=0;x<(n-i)/2;x++) {
            swap(a[x+i],a[n-x-1]);
        }
    }
};