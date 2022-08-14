class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int i = 0;
        int j = n-1;
        int k = 0;
        while(k<=j) {
            if(a[k]==0) {
                swap(a[i],a[k]);
                i++;
                k++;
            }
            else if(a[k]==1) {
                k++;
            }
            else if(a[k]==2) {
                swap(a[j],a[k]);
                j--;
            }
        }
        
        return;
    }
};