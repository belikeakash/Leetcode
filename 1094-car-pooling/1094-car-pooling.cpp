class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& a, int p) {
        // sort(a.begin(),a.end(),cmp);
        int n = a.size();
        map<int,int>m1,m2;
        for(auto x:a) {
            m1[x[1]]+=x[0];
            m2[x[2]]+=x[0];
        }
        int x = 0;
        for(int i=0;i<=1000;i++) {
            x+=m1[i]-m2[i];
            if(x>p) return 0;
        }
        return 1;
    }
};