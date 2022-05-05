class Solution {
public:
    string sortString(string s) {
        vector<int>v(26,0);
        for(auto x:s) {
            v[x-'a']++;
        }       
        string ans = "";
        bool flag = 1;
        int k = 5;
        bool change = 0;
        while(flag) {
            flag = 0;
            string g = "";
            for(int i=0;i<26;i++) {
                if(v[i]>0) {flag = 1; g+=char(i+97); v[i]--;}
            }
            if(change) {
                reverse(g.begin(),g.end());
            }
            change = !change;
            ans+=g;
            cout<<g<<" ";
        }
        return ans;
    }
};