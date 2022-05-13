class Solution {
public:
    int numberOfSubstrings(string s) {
        int c1=0,c2=0,c3=0;
        for(int i=0;i<=2;i++) {
            if(s[i]=='a') c1++;
            else if(s[i]=='b') c2++;
            else if(s[i]=='c') c3++;
        }
        int i = 0,j = 2;
        // if(c1>=0 && c2>=0 && c3>=0) ans+=n-2;
        
        int ans = 0;
        int n = s.size();
        while(j<n) {
            if(c1>=1 && c2>=1 && c3>=1){
                ans+=n-j;
                cout<<j<<" ";
                if(s[i]=='a') c1--;
                if(s[i]=='b') c2--;
                if(s[i]=='c') c3--;
                i++;
                
            }
            else {
                j++;
                if(s[j]=='a') c1++;
                if(s[j]=='b') c2++;
                if(s[j]=='c') c3++;
            }
            
        }
        return ans;
    }
};