class Solution {
public:
    int func(int i, int j, vector<int>&a, bool flag) {
        if(i>j) return 0;
        if(!flag) return max(a[i]+func(i+1, j, a, !flag), a[j]+func(i, j-1, a, !flag));
        return min(-a[i]+func(i+1, j, a, !flag), -a[j]+func(i, j-1, a, !flag));
    }
    bool PredictTheWinner(vector<int>& a) {
        
        int ans = func(0, a.size()-1, a, 0);
        cout<<ans<<" ";
        return ans>=0;
    }
};