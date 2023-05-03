class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0,j=0;
        int ans = 0;
        vector<int>cnt(256,0);
        while(j<n) {
            bool flag = 0;
            cnt[s[j]]++;
            for(int u=0;u<256;u++) {
                if(cnt[u]>1) {
                    flag = 1;
                    break;
                }
            }
            while(flag && i<j) {
                cnt[s[i]]--;
                i++;
                flag = 0;
                for(int u=0;u<256;u++) {
                    if(cnt[u]>1) {
                        flag = 1;
                        break;
                    }
                }
            } 
            //cout<<i<<" "<<j<<endl;
            ans = max(ans,j-i+1);
            j++;
        }
        //cout<<endl;
        return ans;
    }
};