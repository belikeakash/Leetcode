class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
        int n = a.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) {
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        // for(auto x:v) {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        for(int i=0;i<n-1;i++){
            for(int j=i+1; j<n and ((long long)((v[j].first*1L - v[i].first <=t))) ; j++) {
                if(abs(v[j].second - v[i].second) <= k) return 1;
            }
        }
        return 0;
    }
};