class Solution {
public:
    void duplicateZeros(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            if(a[i]==0) {
                for(int j=n-1;j>=i+1;j--) {
                    a[j] = a[j-1];
                }
                i=i+1;
            }
            
        }
        
    }
};