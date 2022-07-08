class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& v, string s) {
        string a1 = "";
        unordered_map<char,int>m1;
        int p = 1;
        for(int i=0;i<s.size();i++) {
            if(m1[s[i]]==0) {m1[s[i]] = p; p++;}
            a1+=to_string(m1[s[i]]);
            a1+="*";
            // cout<<s[i]-s[i-1]<<" ";
        }
        cout<<a1<<"_";
        
        vector<string>ans;
        for(auto x:v) {
            string a2 = "";
            p = 1;
            unordered_map<char,int>m2;
            for(int i=0;i<x.size();i++) {
               if(m2[x[i]]==0) {m2[x[i]] = p; p++;}
                a2+=to_string(m2[x[i]]);
                a2+="*";
            }   
            cout<<a2<<" ";
            if(a2==a1) ans.push_back(x);
        }
        return ans;
    }
};