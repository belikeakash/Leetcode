class Solution {
public:
    int numberOfBeams(vector<string>& x) {
        vector<int>a;
        for(int i=0;i<x.size();i++) {
            string s = x[i];
            int cnt = 0;
            for(int j=0;j<s.size();j++) {
                if(s[j]=='1') cnt++;
            }
            a.push_back(cnt);
        }
        int ans = 0;
        int n = a.size();
        // for(auto p:a) cout<<p<<" ";
        int i1 = 0,i2=0;
        while(i1<n) {
            if(a[i1]==0) i1++;
            else break;
        }
        i2=i1+1;
        while(i2<n) {
            if(a[i2]==0) i2++;
            else break;
        }
        // cout<<a[i1]<<" "<<a[i2]<<endl;
        if(i2>=n) return 0;
        while(i2<n) {
            if(a[i2]==0) i2++;
            // cout<<i2<<" ";
            // if(i1==i2) {
            //     for(int d = i2 + 1; d<n;d++) {
            //         if(a[i2]==0) i2++;
            //         else break;
            //     }
            //     if(i2==n) return ans;
            // }
            else {
                ans+=a[i1]*a[i2];
            i1=i2;
            i2++;
            }
            
            
        }
        return ans;
    }
};