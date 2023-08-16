class Solution {
public:
    int maximumBeauty(vector<int>& a, int k) {
        vector<pair<int, int>>v;
        int n = a.size();
        for(auto x:a) {
            v.push_back({x-k,x+k});
        }
        sort(v.begin(), v.end());
        int mini = v[0].first;
        n = v[v.size()-1].second - v[0].first + 2;
        cout<<n<<endl;
        vector<int>c(n+3, 0);
        for(auto x:v) {
            c[x.first-mini]++;
            c[x.second-mini+1]--;
        }
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            cnt+=c[i];
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};