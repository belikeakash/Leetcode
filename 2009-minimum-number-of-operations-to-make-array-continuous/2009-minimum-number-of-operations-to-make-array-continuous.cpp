class Solution {
public:
    int minOperations(vector<int>& a) {
        
        int m = a.size();
        int z = 0;
        set<int>s;
        int p= 0;
        for(auto &x:a) {
            if(s.find(x)!=s.end()) {
                x=-1;
                p++;
            }
            else {
                s.insert(x);
            }
        }
        sort(a.begin(),a.end());
        int n = a.size();
        int ans = 0;
        for(int i=p;i<n;i++) {
            int l = 0, r = n-1;
             z = -1;
            while(l<=r) {
                int mid = l+(r-l)/2;
                if(a[mid]==a[i]+n-1) {
                    z = mid;
                    break;
                }
                else if(a[mid]<a[i]+n-1) {
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
            if(z!=-1)ans = max(ans,z-i+1);
            else ans = max(ans,r-i+1);
            // cout<<i<<" "<<z<<endl;
        }
        return n-ans;
    }
};