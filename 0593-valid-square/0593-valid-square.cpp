class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b) {
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int,int>>v;
        v.push_back({p1[0],p1[1]});
        v.push_back({p2[0],p2[1]});
        v.push_back({p3[0],p3[1]});
        v.push_back({p4[0],p4[1]});
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<4;i++) {
            for(int j=i+1;j<4;j++) {
                if(v[i]==v[j]) return 0;
            }
        }
        int a1 = sqrt((v[3].second-v[2].second)*(v[3].second-v[2].second) + (v[3].first-v[2].first)*(v[3].first-v[2].first));
        int a2 = sqrt((v[0].second-v[1].second)*(v[0].second-v[1].second) + (v[0].first-v[1].first)*(v[0].first-v[1].first));
        int a3 = sqrt((v[2].first-v[0].first)*(v[2].first-v[0].first) + (v[2].second-v[0].second)*(v[2].second-v[0].second));
        int a4 = sqrt((v[3].first-v[1].first)*(v[3].first-v[1].first) + (v[3].second-v[1].second)*(v[3].second-v[1].second));
        int b1 = sqrt((v[0].second-v[3].second)*(v[0].second-v[3].second) + (v[0].first-v[3].first)* (v[0].first-v[3].first));
        int b2 = sqrt((v[1].second-v[2].second)*(v[1].second-v[2].second) + (v[1].first-v[2].first)* (v[1].first-v[2].first));
        
    if(a1==a2 && a2==a3 && a3==a4 && a4==a1) {
        if(b1==b2) return 1;
    }
        return 0;
    }
};