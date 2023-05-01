class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int i=0,j=n-1;
        while(i<j) {
            if(a[j]==2) {j--; continue;}
            else if(a[i]==2) {
                swap(a[i],a[j]);
                j--;
            }
            i++;
        }
        i=0;
        j=n-1;
        while(i<j) {
            if(a[i]==0) {i++; continue;}
            else if(a[j]==0) {
                swap(a[i],a[j]);
                i++;
            }
            j--;
        }
    }
};