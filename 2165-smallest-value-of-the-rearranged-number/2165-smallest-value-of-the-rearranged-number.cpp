class Solution {
public:
    long long smallestNumber(long long num) {
        if(num>0) {
            string s = to_string(num);
            sort(s.begin(),s.end());
            if(s[0]=='0'){
                int i = 0;
                while(s[i]=='0') i++;
                swap(s[0],s[i]);
            }
            reverse(s.begin(),s.end());
            long long ans = 0;
            for(int i = s.size()-1;i>=0;i--) {
                ans = ans*10 + (s[i]-'0');
            }
            
            return ans;
        }
        else {
            num = -num;
            string s = to_string(num);
            sort(s.begin(),s.end());
            // reverse(s.begin(),s.end());
            long long ans = 0;
            for(int i = s.size()-1;i>=0;i--) {
                ans = ans*10 + (s[i]-'0');
            }
            return -ans;
        }
    }
};