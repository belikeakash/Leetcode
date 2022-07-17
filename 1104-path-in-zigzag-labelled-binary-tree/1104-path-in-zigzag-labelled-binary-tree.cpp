class Solution {
public:
    void func(vector<int>&ans, int n, vector<int>&p) {
        if(n<1) {
            return;
        }
        if(n==1) {
            ans.push_back(1);
            return;
        }
        int x = 0;
        for(int i=0;i<=19;i++) {
            if(p[i]>n) {
                x = i;
                break;
            }
        }
        cout<<n<<"->";
        int u,v;
        u = p[x] - n - 1;
        v = p[x-1] + u;
        cout<<u<<"->";
        cout<<v<<" ";
        ans.push_back(v);
        n = v/2;
        func(ans,n,p);
    }
    vector<int> pathInZigZagTree(int n) {
        vector<int>p(20);
        p[0]=1;
        for(int i=1;i<=19;i++) {
            p[i] = 2*p[i-1];
        }
        // for(auto x:p) cout<<x<<" ";
        vector<int>ans;
        ans.push_back(n);
        n = n/2;
        func(ans,n,p);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};