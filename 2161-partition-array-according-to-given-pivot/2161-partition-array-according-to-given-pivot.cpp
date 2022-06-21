class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int x) {
        int n = a.size();
        vector<int>ans;
        for(int i=0;i<n;i++) {
            if(a[i]<x) ans.push_back(a[i]);
        }
        for(int i=0;i<n;i++) {
            if(a[i]==x) ans.push_back(a[i]);
        }
        for(int i=0;i<n;i++) {
            if(a[i]>x) ans.push_back(a[i]);
        }
        return ans;
    }
};