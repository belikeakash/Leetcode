class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    vector<int>v;
    void func(int i, vector<int>&a) {
        if(i==a.size()-1) {s.insert(a); return;}
        for(int j=i;j<a.size();j++) {
            if(a[j]==a[i] && i!=j) continue;
            swap(a[i],a[j]);
            func(i+1,a);
            swap(a[i],a[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& a) {
        sort(a.begin(),a.end());
        func(0,a);
        for(auto x:s) ans.push_back(x);
        return ans;
    }
};