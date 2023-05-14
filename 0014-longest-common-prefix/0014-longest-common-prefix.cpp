class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";
        int sz = INT_MAX;
        for(int i=0;i<v.size();i++) {
            int n = v[i].size();
            sz = min(sz,n);
        }
        for(int i=0;i<sz;i++) {
            char c = v[0][i];
            for(int j=1;j<v.size();j++) {
                if(v[j][i]!=c) {
                    return ans;
                }
            }
            ans+=c;
        }
        
        return ans;
    }
};