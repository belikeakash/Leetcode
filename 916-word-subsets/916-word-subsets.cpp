class Solution {
public:
    vector<string> wordSubsets(vector<string>& a1, vector<string>& a2) {
        
        vector<int>d(26,0);
        string s = a2[0];
        for(int i=0;i<s.size();i++) {
                d[s[i]-'a']++;
        }
        
        for(auto s:a2) {
            vector<int>f(26,0);
            for(int i=0;i<s.size();i++) {
                f[s[i]-'a']++;
            }
            for(int i=0;i<26;i++) {
                d[i] = max(d[i],f[i]);
            }
        }
          vector<string>ans;
        for(auto s:a1) {
            vector<int>f1(26,0);
            bool flag = 0;
            for(int i=0;i<s.size();i++) {
                f1[s[i]-'a']++;
            }
            for(int i=0;i<26;i++) {
                if(d[i]>f1[i]) {flag = 1; break;}
            }
            if(!flag) ans.push_back(s);
        }
      
        return ans;
    }
};