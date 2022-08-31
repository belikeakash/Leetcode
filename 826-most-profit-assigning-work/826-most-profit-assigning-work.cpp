class Solution {
public:
    int maxProfitAssignment(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<pair<int,int>>v;
        for(int i=0;i<a.size();i++) {
            v.push_back({a[i],b[i]});
        }
        sort(v.begin(),v.end());
        vector<int>maxi(a.size(),0);
        maxi[0]=v[0].second;
        for(int i=1;i<v.size();i++) {
            maxi[i]=max(maxi[i-1],v[i].second);
        }
        int res = 0;
        for(int i=0;i<c.size();i++) {
            int x = c[i];
            int l = 0,r=v.size()-1;
            int ans = -1;
            while(l<=r) {
                int mid = l+(r-l)/2;
                if(v[mid].first<=x) {
                    ans = mid;
                    l = mid+1;
                }
                else {
                    r=mid-1;
                }
            }
            if(ans==-1) continue;
            cout<<maxi[ans]<<" "<<ans<<endl;
            res+=maxi[ans];
        }
        return res;
    }
};