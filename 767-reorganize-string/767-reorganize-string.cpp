class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        int maxi = 0;
        for(auto x:s) {
            m[x]++;
            maxi = max(maxi,m[x]);
        }
        if(maxi > (s.size()-1)/2 + 1 ) return "";
        string s1 = "";
        vector<pair<int,int>>v;
        for(auto x:m) {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(auto x:v) {
            while(x.first--) {
                s1+=x.second;
            } 
        }
        cout<<s1<<" ";
        string ans = s1;
        int n = s1.size();
        for(int i=0;i<n;i+=2) {
            ans[i] = s1[i/2];
        }
        for(int i=1;i<n;i+=2) {
            ans[i] = s1[(i+n)/2];
        }
        return ans;
    }
};