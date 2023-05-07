class Solution {
public:
    string getPermutation(int n, int p) {
        string s = "";
        vector<int>a(n);
        for(int i=1;i<=n;i++) {
            a[i-1] = i;
        }
        // p = 1;
        // p = 9;
        p--;
        while(p--) {
            for(int i=n-1;i>0;i--) {
                if(a[i]>a[i-1]) {
                    int j = i-1;
                    for(int k=n-1;i>=0;k--) {
                        if(a[k]>a[j]) {
                            swap(a[k],a[j]);
                            //cout<<"k"<<k<<endl;
                            break;
                        }
                        
                    }
                    // cout<<"i"<<i<<endl;
                    // cout<<"j"<<j<<endl;
                    reverse(a.begin()+i,a.end());
                    break;
                }
            }
        }
        //cout<<endl;
        string ans = "";
        for(auto x:a) {
            ans+=to_string(x);
        }
        //cout<<endl;
        return ans;
    }
};