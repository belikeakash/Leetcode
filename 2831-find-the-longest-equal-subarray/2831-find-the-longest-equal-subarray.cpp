class Solution {
public:
    int longestEqualSubarray(vector<int>& a, int k) {
        int n = a.size();
        int maxC = 0;
        int maxE = -1;
        int j = 0, i= 0;
        int ans = 0;
        unordered_map<int, int>m;
        while(j<n) {
            m[a[j]]++;
            if(m[a[j]]>maxC) {maxC = m[a[j]]; maxE=a[j];}
            if((j-i+1)-maxC>k) {m[a[i]]--; i++;}
            ans = max(ans, maxC);
            j++;
        }
        
        return ans;
    }
};