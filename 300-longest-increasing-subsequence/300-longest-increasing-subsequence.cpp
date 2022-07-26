class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int>v;
        v.push_back(a[0]);
        for(int i=1;i<a.size();i++) {
            if(a[i]<=v.back()){
                auto j = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
                v[j] = a[i];
            }
            else v.push_back(a[i]);
            
        }
        return v.size();
    }
};