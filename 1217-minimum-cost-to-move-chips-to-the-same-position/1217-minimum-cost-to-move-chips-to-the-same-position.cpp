class Solution {
public:
    int minCostToMoveChips(vector<int>& a) {
        int a1=0,a2=0,n=a.size();
        for(int i=0;i<n;i++) 
        {
            if(a[i]%2==0)a1++;
            else a2++;
        }
        int ans = min(a1,a2);
        return ans;
    }
};