class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int p1 = 0;
        int p2 = 0;
        int i=0,j=0;
        int ans = 0;
        while(j<n) {
            if(s[j]=='T') p1++;
            else p2++;
            int maxi = max(p1,p2);
            int tot = j-i+1;
            if(tot - maxi > k) {
                if(s[i]=='T') p1--;
                else p2--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};