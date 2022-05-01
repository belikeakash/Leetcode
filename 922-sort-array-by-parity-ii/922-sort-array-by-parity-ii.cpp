class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int n = a.size();
        int i=0,j=n-1;
        while(i<j) {
            if(a[i]%2==0) i++;
            else if(a[j]%2!=0) j--;
            swap(a[i],a[j]);
        }
        
        i=1; j=n-2;
        while(i<j) {
            swap(a[i],a[j]);
            i=i+2;
            j=j-2;
        }
        return a;
    }
};