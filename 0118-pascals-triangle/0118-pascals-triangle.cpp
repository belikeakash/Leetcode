class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>v = {1};
        ans.push_back(v);
        if(n==1) {
            return ans;    
        }
        v.push_back(1);
        ans.push_back(v);
        if(n==2) return ans;
        else {
            int o = 3;
            while(o<=n) {
                vector<int>a;
            a.push_back(1);
            for(int i=1;i<v.size();i++) {
                int x = v[i]+v[i-1];
                a.push_back(x);
            }
            a.push_back(1);
            ans.push_back(a);
            v = a;
                o++;
            }
            
            
        }
        return ans;
    }
};