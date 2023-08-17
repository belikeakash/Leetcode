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
        for(auto x:m) {
            int c = x.second.size();
            int u = ((c*(c-1))/2)*8;
            ans+=u;
        }
        
        return ans;
    }
};