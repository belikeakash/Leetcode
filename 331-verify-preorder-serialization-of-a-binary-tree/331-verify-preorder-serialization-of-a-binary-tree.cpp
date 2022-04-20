class Solution {
public:
    bool isValidSerialization(string s) {
        vector<char>v;
        for(int i=0;i<s.size();i++) {
            
            // if(s[i]==',') continue;
            while(i<s.size() && s[i]!=',') {
                i++;
            }
            if(s[i-1]=='#') v.push_back('#');
            else v.push_back('a');
        }
        // for(auto x:v) cout<<x<<" ";
        int n = v.size();
        int cnt=1;
        for(int i=0;i<n;i++) {
            cnt--;
            if(cnt<0) return 0;
            if(v[i]=='a') cnt+=2;
            
        }
        return cnt==0;
    }
};