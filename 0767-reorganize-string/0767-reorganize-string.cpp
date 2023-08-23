class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>m;
        for(auto x:s) m[x]++;
        vector<pair<int, char>>v;
        for(auto x:m) {
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int n = s.size();
        cout<<v[0].first<<" "<<n<<endl;
        if(v[0].first*2>n+1) return "";
        int j = 0;
        string ans = s;
        for(int i=0;i<n;i+=2) {
            if(v[j].first>0) {
                ans[i] = v[j].second;
                v[j].first--;
            }
            else {
                j++;
                ans[i] = v[j].second;
                v[j].first--;
            }
        }
        for(int i=1;i<n;i+=2) {
            if(v[j].first>0) {
                ans[i] = v[j].second;
                v[j].first--;
            }
            else {
                j++;
                ans[i] = v[j].second;
                v[j].first--;
            }
        }
        
        return ans;
    }
};