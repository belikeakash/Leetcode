class Solution {
public:
    string func(int n){
        if(n==1) return "1";
        string s = func(n-1);
        //cout<<s<<" ";
        int cnt = 1;
        string x = "";
        for(int i=0;i<s.size()-1;i++) {
            if(s[i]!=s[i+1]) {
                x+=to_string(cnt);
                x+=s[i];
                cnt = 1;
            }
            else cnt++;
        }
        x+=to_string(cnt);
        x+=s[s.size()-1];
        
        return x;
        
    }
    string countAndSay(int n) {
        return func(n);
    }
};