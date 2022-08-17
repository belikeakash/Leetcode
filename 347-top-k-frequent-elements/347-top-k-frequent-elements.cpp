class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto x:a) {
            if(x>maxi) maxi = x;
            if(x<mini) mini = x;
        }
        vector<int>v(2*max(abs(mini),abs(maxi)) +2,0);
        for(auto x:a) {
            v[-mini+x]++;
        }
        priority_queue<pair<int,int>>q;
        for(int i=0;i<v.size();i++) {
            q.push({v[i],i+mini});
        }
        vector<int>ans;
        while(k--) {
            auto x = q.top();
            q.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};