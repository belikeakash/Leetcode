class Solution {
public:
    int numSpecialEquivGroups(vector<string>& v) {
        map<string,int>m;
        for(auto x:v) {
            int n = x.size();
            string a = "",b="";
            for(int i=0;i<n;i++) {
                if(i%2==0) a+=x[i];
                else b+=x[i];
            }
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            string ans = a+"*"+b;
            cout<<ans<<" ";
            m[ans]++;
        }
        return m.size();
    }
};