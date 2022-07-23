class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n = a.size();
        vector<int>v;
        v.push_back(a[0]);
        for(int i=1;i<n;i++) {
            if(a[i]>v.back()) v.push_back(a[i]);
            else {
                int idx = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
                v[idx] = a[i];
            }
        }
        
        return v.size()>=3 ? 1 : 0;
    }
};