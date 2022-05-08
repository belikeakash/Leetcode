class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>v;
        string p = "";
        int n=0;
        for(auto x:s) {
            if(x==' ') {if(p.size()>n){n = p.size();} v.push_back(p); p="";}
            else p+=x;
        }
        v.push_back(p);
       if(p.size()>n) n = p.size();
        vector<string>ans;
        cout<<n<<endl;
        // for(auto x:v) cout<<x<<" ";
        for(int i=0;i<n;i++) {
            string k = "";
            for(int j=0;j<v.size();j++) {
                if(i<v[j].size()) k+=v[j][i];
                else k+=" ";
            }
            int b = k.size()-1;
            while(b>=0) {
                if(k[b]==' ') {k.pop_back(); cout<<"a";}
                else break;
                b--;
            }
            cout<<k<<" ";
            ans.push_back(k);
        }
        return ans;
        
    }
};