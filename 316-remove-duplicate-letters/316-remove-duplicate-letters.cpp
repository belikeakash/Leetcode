class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>m,m2;
        
        for(auto x:s) m[x]++;
        stack<char>st;
        for(auto x:s) {
            m[x]--;
            if(m2[x]) continue;
            while(!st.empty() && x<st.top() && m[st.top()]>0) {
                    cout<<st.top()<<" ";
                    m2[st.top()]=0;
                    st.pop(); 
                }
            st.push(x); m2[x]=1;
        }
        string ans = "";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};