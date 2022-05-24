class Solution {
public:
    bool solve(vector<int>a, int i, int x) {
        a[i]=a[i-1]=x;
        cout<<x<<" ";
        for(int i=1;i<a.size();i++) {
            if(a[i-1]>a[i]) return 0;
        }
        return 1;
    }
    bool checkPossibility(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        for(int i=1;i<n;i++) {
            if(a[i-1]>a[i]) {
                cnt++;
                return solve(a,i,a[i-1]) || solve(a,i,a[i]);
            }
        }
        return 1;
    }
};