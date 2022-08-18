class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n = a.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i=0;i<n;i++) {
            left[i] = i;
            right[i] = n-i-1;
        }
        stack<int>s;
        for(int i=0;i<n;i++) {
            while(!s.empty() && a[i]<a[s.top()]) {
                right[s.top()] =  i - s.top() - 1;
                s.pop();
            }
            s.push(i);
        }
        stack<int>s2;
        for(int i=n-1;i>=0;i--) {
            while(!s2.empty() && a[i]<=a[s2.top()]) {
                left[s2.top()] = s2.top() - i -1;
                s2.pop();
            }
            s2.push(i);
        }
        long long ans = 0;
        for(int i = 0;i<n;i++) {
            ans += (long long)a[i]*(left[i]+1)*(right[i]+1)%1000000007;
            ans = ans%1000000007;
        }
        return ans;
    }
};