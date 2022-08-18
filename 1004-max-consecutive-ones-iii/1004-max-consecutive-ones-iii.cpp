class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int p1 = 0;
        int p2 = 0;
        int n = a.size();
        int i = 0,j=0;
        int ans = 0;
        while(j<n) {
            if(a[j]==1) p1++;
            else p2++;
            if(p2>k) {
                if(a[i]==1) p1--;
                else p2--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};