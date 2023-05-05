class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n = a.size();
        int x = 0,cnt = 0;
        for(int i=0;i<n;i++){
            if(a[i]==0) {
                cnt = max(cnt,x);
                x = 0;
            }
            else {
                x++;
            }
        }
        cnt = max(x,cnt);
        return cnt;
    }
};