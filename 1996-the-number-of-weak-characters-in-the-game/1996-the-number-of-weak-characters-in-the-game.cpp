class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),cmp);
        stack<pair<int,int>>st;
        int n = a.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            // if(st.empty()) st.push({a[0],a[1]});
            while(!st.empty() && st.top().second < a[i][1] && st.top().first < a[i][0]) {
                st.pop();
                ans++;
            }
            // pair<int,int>p;
            // p.first = a[i]
            st.push({a[i][0],a[i][1]});
        }
        return ans;
    }
};