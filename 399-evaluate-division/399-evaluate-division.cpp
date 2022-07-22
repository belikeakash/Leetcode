class Solution {
public:
    bool DFS( unordered_map<string, vector<string>>&ar, map<string, int>&vis,
            unordered_map<string,double>&m, string &x, string &y, double &ans) {
        if(x==y) {
            return 1;
        }
        vis[x]=1;
        for(auto p:ar[x]) {
            if(vis[p]!=1) {
                ans = ans * m[x+"*"+p];
                cout<<ans<<" ";
                if(DFS(ar,vis,m,p,y,ans)) {
                    return 1;
                }
                else {
                    ans = ans / m[x+"*"+p];
                }
            }
        } 
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& a, vector<double>& v, vector<vector<string>>& q) {
        vector<double>ans;
        unordered_map<string,double>m;
        unordered_map<string, vector<string>>ar;
        for(int i=0;i<a.size();i++) {
            string x = a[i][0];
            string y = a[i][1];
            m[x+"*"+y] = v[i];
            m[y+"*"+x] = 1/v[i];
            
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        for(int i=0;i<q.size();i++) {
            string x = q[i][0];
            string y = q[i][1];
            
            if(ar.find(x)==ar.end() || ar.find(y)==ar.end()) {
                ans.push_back(-1);
            }
            else {
                double val = 1;
                if(x==y) ans.push_back(1);
                else {
                    map<string, int>vis;
                    if(DFS(ar,vis,m,x,y,val)) {
                        ans.push_back(val);
                    }
                    else {
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }
};