class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        if(k>=n) return "0";
        else {
            stack<char>st;
            for(auto x:s) {
                while(!st.empty() && k>0 && st.top()>x) {
                    st.pop();
                    k--;
                }
                st.push(x);
            }
             
            string ans = "";
            while(!st.empty()) {
                ans+=st.top();
                st.pop();
            }
            cout<<ans<<endl;
            reverse(ans.begin(),ans.end());
            while(k>0) {ans.pop_back(); k--;}
            reverse(ans.begin(),ans.end());
            int p = ans.size();
            string q = ans;
            for(int i=p-1;i>0;i--) {
                if(ans[i]=='0') q.pop_back();
                else break;
            }
            reverse(q.begin(),q.end());
            return q;
        }
    }
};