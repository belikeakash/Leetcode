class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        int n = a.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) {
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        vector<int>ans;
        while(i<j) {
            if(v[i].first+v[j].first==x) {
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                return ans;
            }
            else if(v[i].first+v[j].first<x) i++;
            else j--;
        }
        return ans;
    }
};