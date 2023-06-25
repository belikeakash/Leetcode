class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int i = 0, j=0;
        int c = 0;
        int ans = 1;
        int n = a.size();
        while(i<n) {
            if(a[i]==1) i++;
            else if(a[i]==0 && c==0) {i++; c++;}
            else if(a[i]==0 && c==1) {
                while(c>0) {
                    if(a[j]==0) c--;
                    j++;
                }
                i++;
                c++;
            }
            ans = max(ans, i-j);
        }
        return ans-1;
    }
};