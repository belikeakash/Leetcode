class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int i=0,j=1;
        int k = 1;
        while(j<n) {
            if(a[i]==a[j]) {
                j++;
            }
            else {
                a[k]=a[j];
                k++;
                i++;
                j++;
            }
        }
        return k;
    }
};