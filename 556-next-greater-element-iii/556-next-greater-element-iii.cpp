class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>v;
        int y = n;
        while(n>0) {
            int x = n%10;
            v.push_back(x);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        int sz = v.size();
        if(sz==1) return -1;
        int idx = sz-2;
        
        for(int i=sz-2;i>=0;i--) {
            if(v[i]<v[i+1]) {
                idx = i;
                break;
                
            }
        }
        cout<<idx<<" ";
        int prev = INT_MAX;
        int find = idx;
        for(int i=sz-1;i>idx;i--) {
            if(v[i]>v[idx]) {find=i; break;}
        }
        cout<<find<<" ";
        swap(v[idx],v[find]);
        reverse(v.begin()+idx+1, v.end());
        // for(auto x:v) cout<<x<<" ";
        long long ans = 0;
        for(int i=0;i<sz;i++) {
            ans=ans*10 + v[i];
        }
        // cout<<ans<<" "<<n<<endl;
        if(ans==(long long)y) return -1;
        if(ans> 2147483647) return  -1;
        else return ans;
    }
};