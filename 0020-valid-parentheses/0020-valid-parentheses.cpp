class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x:s) {
            bool flag = 0;
            if(st.size()> 0 && st.top()=='{' && x=='}') {st.pop(); flag = 1;}
            if(st.size()> 0 && st.top()=='(' && x==')') {st.pop(); flag = 1;}
            if(st.size()> 0 && st.top()=='[' && x==']') {st.pop(); flag = 1;}    
            if(!flag) st.push(x);
            
        }
        return st.size()==0;
    }
};