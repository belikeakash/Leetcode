class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& a) {
        unordered_map<int,int>m;
        map<pair<int,int>, int>u;
        for(auto x:a) {
            m[x[0]]++;
            m[x[1]]++;
            u[{x[0], x[1]}] = 1;
            u[{x[1], x[0]}] = 1;
        }
        vector<pair<int, int>>maxi;
        for(auto x:m) {
            maxi.push_back({x.second, x.first});
        }
        sort(maxi.begin(), maxi.end());
        reverse(maxi.begin(), maxi.end());
        int ans = 0;
        for(int i=0;i<maxi.size();i++) {
            for(int j=i+1;j<maxi.size();j++) {
                int c = maxi[i].first+maxi[j].first;
                if(u[{maxi[i].second, maxi[j].second}]) c--;
                ans = max(ans, c);
            }
        }
        
        return ans;
    }
};


