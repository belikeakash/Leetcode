class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& a) {
        int n = a.size();
        vector<int>ans;
        if(n==1) {
            ans.push_back(-1);
            return ans;
        }
        for(int i=0;i<n;i++) {
            a[i].push_back(i);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++) {
            cout<<a[i][0]<<" "<<a[i][1]<<endl;
        }
        cout<<endl;
        for(int i=0;i<n;i++) {
            int l = i,r=n-1;
            int c = -1;
            while(l<=r) {
                int mid = l+(r-l)/2;
                if(a[mid][0]>=a[i][1]) {
                    c = a[mid][2];
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
            ans.push_back(c);
        }
        vector<pair<int,int>>o;
        for(int i=0;i<n;i++) {
            o.push_back({a[i][2],ans[i]});
        }
        sort(o.begin(),o.end());
        for(int i=0;i<n;i++) {
            ans[i] = o[i].second;
        }
        return ans;
    }
};