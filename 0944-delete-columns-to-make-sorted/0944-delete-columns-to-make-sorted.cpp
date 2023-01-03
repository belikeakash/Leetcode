class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        vector<string>a;
        for(int i=0;i<v[0].size();i++) {
            string s = "";
            for(int j=0;j<v.size();j++) {
                s+=v[j][i];
            }
            a.push_back(s);
        }
        int ans = 0;
        for(int i=0;i<a.size();i++) {
            // cout<<a[i]<<" ";
            for(int j=1;j<a[i].size();j++) {
                if(a[i][j]<a[i][j-1]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};