class Solution {
public:
    int singleNumber(vector<int>& a) {
        int ans = 0;
        for(int i=0;i<a.size();i++) ans=ans^a[i];
        return ans;
    }
};