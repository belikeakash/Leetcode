class Solution {
public:
    int reverse(int x) {
        vector<int>v1 = {2,1,4,7,4,8,3,6,4,7};
        vector<int>v2 = {2,1,4,7,4,8,3,6,4,8};
        vector<int>v;
        int flag = 0;
        if(x==-2147483648) return 0;
        if(x<0) {flag = 1; x = -x;}
        while(x>0) {
            int c = x%10;
            v.push_back(c);
            x = x/10;
        }
        int n = v.size();
        // for(int i = 0;i<n/2;i++) {
        //     swap(v[i],v[n-i-1]);
        // }
        for(int i=0;i<n;i++) {
            //cout<<v[i]<<" ";
        }
        if(flag) {
            if(n==10) {
                for(int i=0;i<n;i++) {
                    cout<<v[i]<<" "<<v1[i]<<endl;
                    if(v[i]>v2[i]) return 0;
                    else if(v[i]<v2[i]) break;
                }
            }
            if(v==v2) return 0;
        }
        
        else {
            if(n==10) {
                for(int i=0;i<n;i++) {
                    cout<<v[i]<<" "<<v1[i]<<endl;
                    if(v[i]>v1[i]) return 0;
                    else if(v[i]<v1[i]) break;
                }
            }
            if(v==v1) return 0;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            //cout<<v[i]<<" ";
            ans=(ans*10) + v[i];
            //cout<<ans<<" ";
        }
        if(flag) ans = -ans;
        return ans;
    }
};