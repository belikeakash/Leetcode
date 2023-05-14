class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int>s;
        int n = a.size();
        vector<int>right(n);
        for(int i=0;i<n;i++) {
            right[i] = n-i;
        }
        for(int i=0;i<n;i++) {
            while(!s.empty() && a[i]<a[s.top()]) {
                right[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        vector<int>left(n);
        for(int i=0;i<n;i++) {
            left[i] = i+1;
        }
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() && a[i]<a[s.top()]) {
                left[s.top()] = s.top()-i;
                s.pop();
            }
            s.push(i);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            int x = (left[i]+right[i]-1)*a[i];
            ans = max(ans,x);
        }
        
        return ans;
    }
};