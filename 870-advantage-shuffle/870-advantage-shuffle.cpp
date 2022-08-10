class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int>ans(n,-1);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++) {
            v.push_back({b[i],i});
        }
        sort(v.begin(),v.end());
        sort(a.begin(),a.end());
        int p1 = 0;
        vector<int>c;
        int i = 0;
        while(p1<n) {
            cout<<p1<<" ";
            if(a[p1]<=v[i].first) {
                c.push_back(a[p1]);
                p1++;
            }
            else {
                ans[v[i].second] = a[p1];
                i++;
                p1++;
            }
        }
        cout<<endl;
        int j = 0;;
        for(int i=0;i<n;i++) {
            if(ans[i]==-1) {
                ans[i] = c[j];
                j++;
            }
        }
        return ans;
    }
};