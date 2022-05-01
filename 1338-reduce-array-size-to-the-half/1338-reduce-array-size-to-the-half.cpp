class Solution {
public:
    int minSetSize(vector<int>& a) {
        priority_queue<int>q;
        unordered_map<int,int>m;
        for(auto x:a) {
            m[x]++;
        }
        for(auto x:m) {
            q.push(x.second);
        }
        int ans = 0,cnt=0;
        while(ans<a.size()/2) {
            int x = q.top();
            q.pop();
            cnt++;
            ans+=x;
        }
        return cnt;
    }
};