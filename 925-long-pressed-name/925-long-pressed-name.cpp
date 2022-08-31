class Solution {
public:
    bool isLongPressedName(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[i]==t[j]) {
                int x=0,y=0;
                while(i<n-1 && s[i]==s[i+1]) {i++; x++;}
                while(j<m-1 && t[j]==t[j+1]) {j++; y++;}
                if(x>y) return 0;
                i++;
                j++;
            }
            else return 0;
        }
        return (i==n && j==m);
    }
};