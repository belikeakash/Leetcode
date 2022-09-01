class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int,int>m;
        for(auto &x:a) {
            if(x%2==0) x = 0;
            else x = 1;
        }
        int ans = 0;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum+=a[i];
            ans+=m[sum-k];
            m[sum]++;
            if(sum==k) ans++;
        }
        return ans;
    }
};