class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            a.push_back(a[i]);
        }
        n = a.size();
        vector<int>p(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++) {
            while(!s.empty() && a[i]>a[s.top()]) {
                p[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
        vector<int>ans(n/2,-1);
        for(int i=0;i<n/2;i++) ans[i]=p[i];
        return ans;
    }
};