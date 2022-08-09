class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>&b) {
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),cmp);
        vector<vector<int>>ans;
        for(int i=0;i<a.size();i++) {
            ans.insert(ans.begin()+a[i][1],a[i]);
        }
        return ans;
    }
};