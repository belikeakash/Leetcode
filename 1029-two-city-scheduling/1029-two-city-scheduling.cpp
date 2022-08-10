class Solution {
public:
    unordered_map<string,int>m;
    int func(vector<vector<int>>& a, int i, int x,int y) {
        if(i>=a.size()) return 0;
        int ans1 = 100000;
        int ans2 = 100000;
        int ans3 = 100000;
        string s = to_string(i)+"*"+to_string(x)+"*"+to_string(y);
        if(m.count(s)) return m[s];
        if(x>0 && y>0) {
            ans1 = min(a[i][0]+func(a,i+1,x-1,y),a[i][1]+func(a,i+1,x,y-1));
        }
        else if(x>0 && y<=0) {
            ans2 = a[i][0]+func(a,i+1,x-1,y);
        }
        else if(y>0 && x<=0) {
            ans3 = a[i][1]+func(a,i+1,x,y-1);
        }
        return m[s] = min({ans1,ans2,ans3});
    }
    int twoCitySchedCost(vector<vector<int>>& a) {
        int n = a.size();
        n = n/2;
        return func(a,0,n,n);
    }
};