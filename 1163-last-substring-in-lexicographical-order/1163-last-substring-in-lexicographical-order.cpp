class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = n-2;
        int j;
        int maxi = n-1;
        while(i>=0) {
            if(s[i]>s[maxi]) {
                maxi = i;
            }
            else if(s[i]==s[maxi]) {
                int p1=i+1;
                int p2=maxi+1;
                while(p1<maxi && p2<n && s[p1]==s[p2]) {
                    p1++;
                    p2++;
                }
                if(p1==maxi || p2==n || s[p1]>s[p2]) {
                    maxi = i;
                }
            }
            i--;
        }
        // cout<<maxi<<" ";
        // string ans = "";
        // for(int k=maxi;k<n;k++) ans+=s[k];
        // return ans;
        return s.substr(maxi);

    }
};