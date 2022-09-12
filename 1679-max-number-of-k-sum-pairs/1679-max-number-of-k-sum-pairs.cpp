class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        int n = a.size();
        int ans = 0;
        unordered_map<int,int>m;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++) {
            if(m[k-a[i]]) {
                ans++;
                m[k-a[i]]--;
            }
            else {
                m[a[i]]++;
            }
        }
        return ans;
    }
};