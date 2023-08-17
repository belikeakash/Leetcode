class Solution {
public:
    int tupleSameProduct(vector<int>& a) {
        unordered_map<int, set<pair<int, int>>>m;
        int n = a.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(a[i]!=a[j]){m[a[i]*a[j]].insert({a[i], a[j]});}
            }
        }
        
        //for(auto x:m) cout<<x.first<<" "<<x.second.size()<<endl;
        int ans = 0;
        unordered_map<int, int>m2;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int c = a[i]*a[j];
                if(a[i]!=a[j] && m[c].size()>1 && !m2[c]) {
                    int u = m[c].size();
                    int x = (u*(u-1))/2;
                    m2[c]=1;
                    ans+=(x)*8;
                }
            }
        }
        
        return ans;
    }
};