class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int>s;
        for(int i=0;i<n;i++) {
            bool flag = 0;
            s.push(a[i]);
            while(s.size()>1) {
                int c1 = s.top();
                s.pop();
                int c2 = s.top();
                s.pop();
                
                if(c1<0 && c2>0) {
                    flag = 1;
                    int c=-1 ;
                    if(abs(c1) > abs(c2)) {
                        c = c1;
                        s.push(c);
                    }
                    else if(abs(c1) < abs(c2)) {
                        c = c2;
                        s.push(c);
                    }
                    
                    //cout<<c<<endl;
                }
                else {s.push(c2); s.push(c1); break;}
            }
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