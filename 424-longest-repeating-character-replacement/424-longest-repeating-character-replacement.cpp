class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>v(26,0);
        int i = 0,j=0;
        int p = 0;
        int maxi = 0;
        int ans = 0;
        int n = s.size();
        unordered_map<char,int>m;
        while(j<n) {
            m[s[j]]++;
            maxi = max(maxi,m[s[j]]);
            if(j-maxi-i + 1 > k) {
                m[s[i]]--;
                i++;
             
            }
               ans = max(ans,j-i+1);
            j++;
        }
        cout<<endl;
        return ans;
    }
};