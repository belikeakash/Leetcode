class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int i = n-1;
        while(i>0) {
            if(a[i]<=a[i-1]) i--;
            else {
                
                int j = i;
                int pos = j;
                while(j<n && a[j]>a[i-1]) {
                    if(a[j]<a[pos]) {
                        pos = j;
                    }
                    j++;
                }
                //cout<<i<<" "<<pos;
                swap(a[i-1], a[pos]);
                sort(a.begin()+i, a.end());
                return;
            }
        }
        reverse(a.begin(), a.end());
    }
};