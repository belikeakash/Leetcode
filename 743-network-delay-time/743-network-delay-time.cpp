class Solution {
public:
    int INF = INT_MAX;
    int networkDelayTime(vector<vector<int>>& v, int n, int k) {
        vector<int>d(n+1,INF);
        // cout<<n<<endl;
        vector<vector<pair<int,int>>>ar(n+1);
        for(int i=0;i<v.size();i++) {
            cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
            ar[v[i][0]].push_back({v[i][1],v[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        d[k] = 0;
        cout<<k<<" ";
        while(!q.empty()) {
            int curr = q.top().second;
            cout<<curr<<" ";
            int curr_d = q.top().first;
            q.pop();
            for(auto x:ar[curr]) {
                if(curr_d + x.second < d[x.first]) {
                    d[x.first] = curr_d + x.second;
                    q.push({d[x.first],x.first});
                }
            }
        } 
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans = max(ans,d[i]);
            if(d[i]==INF) return -1;
        }
        return ans;
    }
};