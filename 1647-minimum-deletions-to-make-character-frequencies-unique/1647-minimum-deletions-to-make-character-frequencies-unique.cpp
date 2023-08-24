class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>m;
        for(auto x:s) m[x]++;
        vector<int>v;
        for(auto x:m) {
            v.push_back(x.second);
        }
        m.clear();
        sort(v.begin(), v.end());
        int x = v[v.size()-1];
        int i = v.size()-1;
        int cnt = 0;
        while(i>=0) {
            //cout<<i<<" ";
            while(m.count(v[i]) && v[i]>0) {
                cnt++;
                v[i]--;
            }
            m[v[i]]=1;
            i--;
        }
        
        return cnt;
    }
};