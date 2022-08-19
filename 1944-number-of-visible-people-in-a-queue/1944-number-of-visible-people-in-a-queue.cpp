class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& a) {
        int n = a.size();
        vector<int>right(n,0);
        
        stack<int>s;
        for(int i=0;i<n;i++) {
            int ans = 0;
            while(!s.empty() && a[i]>a[s.top()]) {
                int x = s.top();
                s.pop();
                right[x]++;
            }
            if(!s.empty()) {
                right[s.top()]++;
            }
            s.push(i);
        }
        return right;
    }
};