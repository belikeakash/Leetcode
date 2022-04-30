class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        map<int,int>bm;
        vector<int>v(26,0);
        for(int j=0;j<a[0].size();j++) {
            string s = a[0];
            v[s[j]-'a']++;
        }
        vector<int>d(26,0);
        for(int i=1;i<a.size();i++) {
            
            for(int j=0;j<a[i].size();j++) {
                string s = a[i];
                d[s[j]-'a']++;
            }
            for(int j=0;j<26;j++) {
                v[j] = min(v[j],d[j]);
                d[j]=0;
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++) {
            while(v[i]>0) {
                char x = i+ 'a';
					string s ;
					s = x;
					ans.push_back(s);
                    v[i]--;
            }
        }
        return ans;
    }
};