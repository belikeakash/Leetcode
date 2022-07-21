class Solution {
public:
    vector<vector<pair<int,int>>>ar;
    
    int findTheCity(int n, vector<vector<int>>& v, int t) {
        ar.resize(n);
        for(int i=0;i<v.size();i++) {
            int x = v[i][0];
            int y = v[i][1];
            int z = v[i][2];
            ar[x].push_back({y,z});
            ar[y].push_back({x,z});
        }
        vector<vector<int>>a;
        for(int i=0;i<n;i++) {
            vector<int>d(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
            q.push({0,i});
            d[i] = 0;
            while(!q.empty()) {
                int curr = q.top().second;
                int curr_d = q.top().first;
                q.pop();
                for(auto x:ar[curr]) {
                    if(curr_d + x.second < d[x.first]) {
                        d[x.first] = curr_d + x.second;
                        q.push({d[x.first],x.first});
                    }
                }
            }
            a.push_back(d);
        }
            
            int ans = INT_MAX;
            int vv = -1;
            for(int i=0;i<a.size();i++) {
                int u = 0;
                for(int j=0;j<a[i].size();j++) {
                    if(a[i][j]<=t) u++; 
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
                if(u<=ans) {
                    ans = u;
                    vv = i;
                }
            }
            return vv;
        
        
    }
};