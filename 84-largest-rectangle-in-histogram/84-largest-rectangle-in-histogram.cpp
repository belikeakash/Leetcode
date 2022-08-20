class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int>l1(n,0);
        vector<int>r1(n,0);
        for(int i=0;i<n;i++) {
            l1[i]=i;
            r1[i]=n-i-1;
        }
        stack<int>s1;
        for(int i=0;i<n;i++) {
            while(!s1.empty() && a[i]<a[s1.top()]) {
                r1[s1.top()] = i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        stack<int>s2;
        for(int i=n-1;i>=0;i--) {
            while(!s2.empty() && a[i]<=a[s2.top()]) {
                l1[s2.top()] = s2.top() - i - 1;
                s2.pop();
            }
            s2.push(i);
        }
        
        vector<int>p1(n,0);
        int ans = 0;
        for(int i=0;i<n;i++) {
            p1[i] = (l1[i]+r1[i])+1;
            ans = max(ans,p1[i]*a[i]);
        }
        cout<<endl;
        return ans;
        
        
    }
};