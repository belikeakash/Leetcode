class Solution {
public:
    int leastInterval(vector<char>& a, int n) {
        unordered_map<char,int>m;
        int maxi = 0;
        for(auto x:a) {m[x]++; maxi = max(maxi,m[x]);}
        int ans = (maxi-1)*(n+1);
        for(auto x:m) {
            if(x.second==maxi) ans++;
        }
        return max(ans,(int)a.size());
    }
};