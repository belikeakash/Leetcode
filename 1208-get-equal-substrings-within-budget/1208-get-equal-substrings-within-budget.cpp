class Solution {
public:
    int equalSubstring(string s, string t, int u) {
        vector<int>a;
        for(int i=0;i<s.size();i++) {
            a.push_back(abs(s[i]-t[i]));
        }
        // for(auto x:a) cout<<x<<" ";
        int ans = 0;
        int sum = 0;
        int n = s.size();
        int i=0,j=0;
        while(j<n) {
            sum+=a[j];
            while(sum>u) {
                sum=sum-a[i];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};