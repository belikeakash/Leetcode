class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a1, vector<int>& a2, int k) {
        int n1 = a1.size();
        int n2 = a2.size();
        priority_queue<pair<int, pair<int,int>>>q;
        for(auto x:a1) {
            for(auto y:a2) {
                if(q.size()<k) {
                    vector<int>v;
                    v.push_back(x);
                    v.push_back(y);
                    q.push({x+y,{x,y}});
                }
                else if(x+y<q.top().first) {
                        q.pop();
                        q.push({x+y,{x,y}});
                }
                else break;
            }
        }
        vector<vector<int>>ans;
        while(!q.empty()) {
            ans.push_back({q.top().second.first,q.top().second.second});
            q.pop();
        }
        return ans;
    }
};