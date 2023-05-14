class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int n = s.size();
        //int n = s.size();
        int ans = 0;
        int i = 0;
        while(i<n) {
            cout<<i;
            if(s[i]=='I' && (i+1<n && (s[i+1]=='V' || s[i+1]=='X'))) {
                cout<<"a";
                ans+=m[s[i+1]] - m[s[i]];
                i=i+2;
            }
            else if(s[i]=='X' && (i+1<n && (s[i+1]=='L' || s[i+1]=='C'))) {
                cout<<"b";
                ans+=m[s[i+1]] - m[s[i]];
                i=i+2;
            }
            else if(s[i]=='C' && (i+1<n && (s[i+1]=='D' || s[i+1]=='M'))) {
                cout<<"c";
                ans+=m[s[i+1]] - m[s[i]];
                i=i+2;
            }
            else {cout<<"d";ans+=m[s[i]]; i=i+1;}
            //cout<<ans<<" ";
        }
        cout<<endl;
        
        return ans;
    }
};