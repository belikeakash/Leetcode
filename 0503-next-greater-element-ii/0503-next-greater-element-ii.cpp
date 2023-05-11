class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        vector<int>a = v;
        for(auto x:v) {
            a.push_back(x);
        }
        
        stack<int>s;
        int n = a.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++) {
            while(!s.empty() && a[i]>a[s.top()]) {
                ans[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
        int c = v.size();
        v.clear();
        for(int i=0;i<c;i++) {
            v.push_back(ans[i]);
        }
        
        return v;
    }
};