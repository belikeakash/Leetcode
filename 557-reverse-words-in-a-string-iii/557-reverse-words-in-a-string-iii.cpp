class Solution {
public:
    string reverseWords(string s) {
        int i=0,n=s.size();
        string ans = "";
        string x=" ";
        while(i<n) {
            if(s[i]==' ') {
                reverse(x.begin(),x.end());
                ans+=x;
                // ans+=" "
                x="";
            }
            
        
            x+=s[i];
            i++;
            if(i==n) {
                reverse(x.begin(),x.end());
                ans+=x;
                // ans+=" ";
            }
            
        }
        ans.pop_back();
        cout<<i<<endl;
        return ans;
    }
};