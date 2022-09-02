class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b) {
        if(a.second==b.second) return a.first>b.first;
        return a.second<b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        int n = profits.size();
        for(int i=0;i<n;i++) {
            v.push_back({profits[i],capital[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int ans = 0;
        priority_queue<int>q;
        int i = 0;
        while(k--) {
            while(i<n && v[i].second<=w) {q.push(v[i++].first);}
            if(!q.empty()) {
                w+=q.top();
                q.pop();
            }
        }
        return w;
    }
};