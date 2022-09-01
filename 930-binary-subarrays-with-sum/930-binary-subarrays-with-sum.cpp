class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int x) {
        unordered_map<int,int>m;
        int n = a.size();
        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            sum+=a[i];
            
            ans+=m[sum-x];
            m[sum]++;
            if(sum==x) ans++;
        }
        return ans;
    }
};