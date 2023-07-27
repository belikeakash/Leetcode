class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>s;
        int n = a.size();
        for(int i=0;i<n;i++) {
            bool flag = 0;
            while(!s.empty() && s.top()>0 && a[i]<0) {
                if(abs(s.top())>abs(a[i])) {
                    flag=1;
                    break;
                }
                else if(abs(s.top())<abs(a[i])) {
                    s.pop();
                }
                else {
                    flag=1;
                    s.pop();
                    break;
                }
            }
            
            if(!flag) s.push(a[i]);
        }
                        
        vector<int>ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};