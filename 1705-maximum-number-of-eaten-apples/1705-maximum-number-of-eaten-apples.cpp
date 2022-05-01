class Solution {
public:
    int eatenApples(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int i=0;
        while(i<n || q.size()) {
            if(i<n && a[i]>0) q.push({i+b[i]-1,a[i]});
            while(q.size() && q.top().first<i) {
                q.pop();
            }
            if(q.size()) {
                auto x = q.top();
                q.pop();
                if(x.second>1) {
                    q.push({x.first,x.second-1});
                }
                ans++;
            }
            i++;
            
        }
        return ans;
    }
};