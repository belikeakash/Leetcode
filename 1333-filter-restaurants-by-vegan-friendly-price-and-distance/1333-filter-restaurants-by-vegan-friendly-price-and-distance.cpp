class Solution {
public:
    static bool comp(pair<int,int>a,pair<int,int>b) {
        if(a.second==b.second) return a.first>b.first;
        return a.second>b.second;
    }
    vector<int> filterRestaurants(vector<vector<int>>& a, int x, int y, int z) {
        vector<pair<int,int>>ans;
        for(auto i:a) {
            if(x==1) {
                if(i[2]==0) continue;
                else {
                    if(i[3]<=y && i[4]<=z) ans.push_back({i[0],i[1]});
                }
            }
            else {
                if(i[3]<=y && i[4]<=z) ans.push_back({i[0],i[1]});
            }
        }
        sort(ans.begin(),ans.end(),comp);
        vector<int>p;
        for(auto x:ans) {
            p.push_back(x.first);
        }
        // reverse(p.begin(),p.end());
        return p;
    }
};