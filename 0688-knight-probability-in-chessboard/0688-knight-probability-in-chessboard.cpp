class Solution {
public:
    vector<int> dx ={2,2,-2,-2,1,1,-1,-1};
    vector<int> dy ={1,-1,-1,1,2,-2,-2,2};
    unordered_map<string, double>mp;
    double func(int n, int k, int row, int col) {
        if(k<0 || row<0 || row>=n || col<0 || col>=n) return 0;
        if(k==0) return 1;
        string s = to_string(k) + "+" + to_string(row) + "+" + to_string(col);
        if(mp.count(s)) return mp[s];
        double tot = 0;
        for(int i=0;i<8;i++) {
            tot+=func(n, k-1, row+dx[i], col+dy[i]);
        }
        double ans = (double)tot/(double)8;
        return mp[s] = ans;
    }
    double knightProbability(int n, int k, int row, int col) {
        double ans = 0;
        return func(n, k, row, col);
    }
};