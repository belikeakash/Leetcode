class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,n=s.size(),r=n-1;
        while(l<r) {
            if((s[l]<65 || s[l]>90) && (s[l]<97 || s[l]>122)) l++;
            else if((s[r]<65 || s[r]>90) && (s[r]<97 || s[r]>122)) r--;
            else {swap(s[l],s[r]);
            l++;r--;}
        }
        return s;
    }
};