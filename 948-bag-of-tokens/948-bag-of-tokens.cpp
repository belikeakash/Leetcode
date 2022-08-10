class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        int n = a.size();
        sort(a.begin(),a.end());
        int i = 0;
        int j = n-1;
        int x = 0;
        while(i<=j) {
            if(x==0) {
                if(p>=a[i]) {
                    x++;
                    p = p-a[i];
                    i++;
                }
                else return x;
            }
            else {
                // if(p<a[i]) return x;
                if(p>=a[i]) {
                    x++;
                    p = p - a[i];
                    i++;
                }
                else if(j-i>1) {
                    x--;
                    p = p + a[j];
                    j--;
                }
                else return x;
            }
            
        }
        return x; 
    }
};