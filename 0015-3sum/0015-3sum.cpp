class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>>ans;
        int n = a.size();
        sort(a.begin(), a.end());
        for(int i=0;i<n-2;i++) {
            if(i>0 && a[i]==a[i-1]) continue;
            int j = i+1, k = n-1;
            while(j<k) {
                if(a[i]+a[j]+a[k]==0) {
                    ans.push_back({a[i], a[j], a[k]});
                    while(j<n-1 && a[j]==a[j+1]) j++;
                    while(k>0 && a[k]==a[k-1]) k--;
                    j++;
                    k--;
                }
                else if(a[i]+a[j]+a[k]>0) k--;
                else j++;
            }
            
        }
        
        return ans;
    }
};