class Solution {
public:
    int compare(string &a, string &b) {
        int x = 0;
        int i = 0;
        //cout<<a<<" "<<b<<endl;
        // while(a[i]=='0') i++;
        for(int j=i;j<a.size();j++) x=x*10 + (a[j]-'0');
        int y= 0;
        i = 0;
        // while(b[i]=='0') i++;
        for(int j=i;j<b.size();j++) y=y*10 + (b[j]-'0');
        // if(x.size()!=y.size()) {
        //     string p = "";
        //     int n1 = x.size();
        //     int n2 = y.size();
        //     int u = abs(n1-n2);
        //     for(int i=0;i<u;i++) p+='0';
        //     if(x.size()<y.size()) x+=p;
        //     else y+=p;
        // }
        //cout<<x<<" "<<y<<"+"<<endl;
        if(x==y) return 0;
        else if(x>y) {return 1;}
        return -1;
    }
    int compareVersion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int sz = max(n,m);
        int ans = 0;
        string a = "", b="";
        int i = 0,j = 0;
        bool flag1 = 0, flag2 = 0;
        while(i<sz && j<sz) {
            
            if((i< n && s1[i]=='.') || i>=n) {flag1 = 1; i++;}
            else if(!flag1 && i<n && s1[i]!='.') {a+=s1[i]; i++;}
            if((j< m && s2[j]=='.') || j>=m) {flag2 = 1; j++;}
            else if(!flag2 && j<m && s2[j]!='.') {b+=s2[j]; j++;}
            //cout<<a<<" "<<b<<endl;
            if(flag1 && flag2) {
                //cout<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
                ans = compare(a, b);
                if(ans==1 || ans==-1) return ans;
                a = "";
                b = "";
                flag1 = 0;
                flag2 = 0;
            }
        }
        //cout<<a<<" "<<b<<endl;
        ans = compare(a,b);
        //cout<<ans<<endl;
        //cout<<endl;
        return ans;
    }
};