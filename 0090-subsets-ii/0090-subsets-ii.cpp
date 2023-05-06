class Solution {
public:
    set<vector<int>>s;
    vector<vector<int>>u;
    void func(int i, int n, vector<int>&a,vector<int>v) {
        if(i==n) {
            u.push_back(v);
            return;
        }
        int cnt = 1;
        int j = i;
        while(j+1<n && a[j]==a[j+1]) {
            cnt++;
            j++;
        }
        for(int x=0;x<=cnt;x++) {
            func(i+cnt,n,a,v);
            v.push_back(a[i]);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<int>v;
        sort(a.begin(),a.end());
        func(0,a.size(),a,v);
        
        // vector<vector<int>>ans;
        // for(auto x:s) {
        //     ans.push_back(x);
        // }
        return u;
    }
};