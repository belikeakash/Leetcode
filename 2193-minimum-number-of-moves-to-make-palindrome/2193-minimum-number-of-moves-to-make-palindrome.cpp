class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int i=0;
        int j = n-1;
        int ans = 0;
        while(i<=j) {
            if(s[i]!=s[j]) {
                int r = j-1;
                int l = i+1;
                int p1=0;
                int p2=0;
                while(r>i && s[i]!=s[r]) {
                    p1++;
                    r--;
                }
                while(l<j && s[j]!=s[l]) {
                    p2++;
                    l++;
                }
                // cout<<r<<" "<<l<<" ";
                if(p1<p2) {
                    while(r<=j-1) {
                        swap(s[r],s[r+1]); ans++;
                        r++;
                    }
                }
                else {
                    while(l>i){
                        swap(s[l],s[l-1]); ans++;
                        l--;
                    }
                    
                }
            }
            // cout<<s<<endl;
            i++;
            j--;
        }
        return ans;
    }
};