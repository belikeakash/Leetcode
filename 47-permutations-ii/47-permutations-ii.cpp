class Solution {
public:
    vector<vector<int>>ans;
    
    vector<int>v;
    void func(int i, vector<int>&a) {
        if(i==a.size()-1) {ans.push_back(a); return;}
        set<int>s;
        for(int j=i;j<a.size();j++) {
            if(s.count(a[j])==1) continue;
            s.insert(a[j]);
            swap(a[i],a[j]);
            func(i+1,a);
            swap(a[i],a[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& a) {
        sort(a.begin(),a.end());
        func(0,a);
        // for(auto x:s) ans.push_back(x);
        return ans;
    }
};