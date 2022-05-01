class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int i=0,j=a.size()-1;
        int n = a.size();
        while(i<j) {
            if(a[i]%2==0) i++;
            else if(a[j]%2!=0) j--;
            swap(a[i],a[j]);
        }
        return a;
    }
};