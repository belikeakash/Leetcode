class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char>st;
        for(auto x:s) {
            while(!st.empty() && k>0 && x<st.top()) {
                st.pop();
                k--;
            }
            if(x!='0' || !st.empty()) st.push(x);
        }
        while(k-->0 && !st.empty()) st.pop();
        string ans="";
        if(st.empty()) return "0";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};