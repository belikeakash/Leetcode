class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        long long ans = 0;
        for(int j=0;j<n;j++) {
            if(s[j]==' ') break;
        }
        char sign = '+';
        bool flag = 0;
        while(i<n && s[i]==' ') i++;
        while(i<n) {
            if((s[i]=='-' || s[i]=='+') && flag>0) {
                return sign=='-'? -ans : ans;
            }
            if((s[i]=='-' || s[i]=='+') && !flag) {
                if(s[i]=='-') {sign = '-'; i++; flag = 1; continue;}
                else if(s[i]=='+') {sign = '+'; i++; flag = 1; continue;}
            }
            
            int c = s[i]-'0';
            //cout<<c<<" ";
            if(c>=0 && c<=9) {
                flag = 2;
                ans = ans*10 + c;
                cout<<ans<<" ";
                if(sign =='+' && ans>INT_MAX) {ans = INT_MAX; return ans;}
                if(sign =='-' && -ans<INT_MIN) {ans = INT_MIN; return ans;}
            }
            else {
                return sign=='-'? -ans : ans;
            }
            i++;
        }
        if(sign=='-') ans = -ans;
        
        return ans;
    }
};