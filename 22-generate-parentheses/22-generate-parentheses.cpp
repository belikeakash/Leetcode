class Solution {
public:
    void func(int i,int j,vector<string>&v, string s) {
        if(i==0 && j==0) {
            v.push_back(s);
            return;
        }
        if(i>0) {func(i-1,j+1,v,s+'(');}
        if(j>0) {func(i,j-1,v,s+')');}
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        vector<string>v;
        func(n,0,v,"");
        for(auto x:v) {
            cout<<x<<" ";
        }
        
        // for(auto x:v) {
        //     string s = x;
        //     stack<char>st;
        //     for(int i=0;i<s.size();i++) {
        //         if(st.size()==0) st.push(s[i]);
        //         if(st.top()=='(' && s[i]==')') st.pop();
        //         else {
        //             st.push(s[i]);
        //         }
        //     }
        //     cout<<st.size()<<" ";
        //     if(st.size()==0) ans.push_back(x);
        // }
        return v;
    }
};