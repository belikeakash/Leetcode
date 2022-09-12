class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        vector<int>v(a.size(),0);
        v[0]=a[0];
        for(int i=1;i<a.size();i++) {
            v[i]=a[i]+v[i-1];
        }
        int ans = 0;
        unordered_map<int,int>m;
        for(int i=0;i<v.size();i++) {
            if(v[i]==k) ans++;
            ans+=m[v[i]-k];
            m[v[i]]++;
        }
        return ans;
    }
};