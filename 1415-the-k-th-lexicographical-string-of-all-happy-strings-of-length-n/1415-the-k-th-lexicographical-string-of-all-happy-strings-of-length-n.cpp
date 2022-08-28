class Solution {
public:
    vector<char>v={'a','b','c'};
    string s;
    vector<string>ans;
    void func(int i, int n) {
        if(i==n) {
            ans.push_back(s);
            return;
        }
        for(int j=0;j<3;j++) {
            s+=v[j];
            func(i+1,n);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        func(0,n);
        vector<string>u;
        // for(auto x:ans) cout<<x<<" ";
        // u.push_back(ans[0]);
        for(int i=0;i<ans.size();i++) {
            bool flag = 0;
            for(int j=1;j<ans[i].size();j++) {
                if(ans[i][j]==ans[i][j-1]) {flag=1; break;}
            }
            if(flag==0) u.push_back(ans[i]);
        }
        sort(u.begin(),u.end());
        // cout<<u[0];
        if(k>u.size()) return "";
        
        return u[k-1];
    }
};