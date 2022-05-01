class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int n = a.size();
        int i=0,j=n-1;
        vector<int>ans;
        while(i<=j) {
            if(a[i]*a[i]>a[j]*a[j]) {ans.push_back(a[i]*a[i]); i++;}
            else {ans.push_back(a[j]*a[j]);j--;}
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};