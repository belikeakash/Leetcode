class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";
        vector<bool>check(26,0);
        vector<int>count(26,0);
        for(auto x:s) {
            count[x-'a']++;
        }
        for(int i=0;i<s.size();i++) {
            char c = s[i];
            if(check[c-'a']) {count[c-'a']--; continue;}
            // else if(ans.size()==0) {ans.push_back(c); check[c-'a']=1; count[c-'a']--;}
            while(ans.size()>0 && c<ans.back() && count[ans.back()-'a'] > 0) {
                check[ans.back()-'a']=0;
                ans.pop_back();
                // cout<<ans<<"*";
            }
            ans.push_back(c);
                check[c-'a']=1;
                count[c-'a']--;
            
            cout<<ans<<" ";
        }
        return ans;
    }
};