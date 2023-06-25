class Solution {
public:
    bool closeStrings(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1!=n2) return 0;
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        set<char>st1,st2;
        for(auto x:s1) {v1[x-'a']++; st1.insert(x);}
        for(auto x:s2) {v2[x-'a']++; st2.insert(x);}
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return (v1==v2 && st1==st2);
    }
};