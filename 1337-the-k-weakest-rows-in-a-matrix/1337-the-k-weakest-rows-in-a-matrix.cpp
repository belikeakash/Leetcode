class Solution {
public:
    static bool comp(pair<int,int>a,pair<int,int>b) {
        if(a.first<b.first) return 1;
        else if(a.first==b.first) return a.second<b.second;
        else return 0;
        
    }
    vector<int> kWeakestRows(vector<vector<int>>& a, int k) {
        vector<pair<int,int>>ans;
        for(int i=0;i<a.size();i++) {
            int cnt = 0;
            for(int j=0;j<a[0].size();j++) {
                if(a[i][j]==1) cnt++;
                else break;
            }
            ans.push_back({cnt,i});
        }
        for(auto x:ans) {
                cout<<x.first<<" "<<x.second<<endl;
            }
        sort(ans.begin(),ans.end(),comp);
        vector<int>x;
        for(int i=0;i<k;i++) {
            x.push_back(ans[i].second);
        }
        return x;
    }
};