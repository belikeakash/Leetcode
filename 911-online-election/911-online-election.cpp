class TopVotedCandidate {
public:
    map<int,int>m;
    int z = -1;
    TopVotedCandidate(vector<int>& b, vector<int>& c) {
        int n = b.size();
        vector<int>a(n+1,-1);
        int maxi = b[0];
        for(int i=0;i<n;i++) {
            a[b[i]]++;
            if(a[b[i]]>=a[maxi]) {
                maxi = b[i];
            }
            m[c[i]] = maxi;
            z = c[i];
        }
    }
    
    int q(int t) {
        int ans = -1;
        auto x = m.lower_bound(t);
        if(x->first!=t) x--;
        return x->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */