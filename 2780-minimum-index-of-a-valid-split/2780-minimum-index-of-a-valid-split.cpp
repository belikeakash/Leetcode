class Solution {
public:
    int minimumIndex(vector<int>& a) {
        unordered_map<int,int>m;
        for(auto x:a) m[x]++;
        int n = a.size();
        int maxi = 0;
        int ele = -1;
        for(auto x:m) {
            if(x.second>maxi) {
                maxi = x.second;
                ele = x.first;
            }
        }
        if(maxi*2<=n) return -1;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(a[i]==ele) cnt++;
            if(cnt*2>i+1 && (maxi-cnt)*2>(n-i-1)) return i;
        }
        return -1;
    }
};