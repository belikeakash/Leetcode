class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string>ans;
        if(n<10) return ans;
        unordered_map<string,int>m;
        string k = "";
        for(int i=0;i<10;i++) {
            k+=s[i];
        }
        m[k]++;
        for(int i=10;i<n;i++) {
            k+=s[i];
            k.erase(k.begin());
            m[k]++;
            cout<<k<<endl;
        }
        for(auto x:m) {
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second>1) ans.push_back(x.first);
        }
        return ans;
    }
};