class Solution {
public:
    vector<string> letterCombinations(string s) {
        vector<string>ans;
        vector<string>v={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(s.size()==0) return ans;
        queue<string>q;
        string p = "";
        q.push(p);
        for(int i=0;i<s.size();i++) {
            int n = q.size();
            for(int j=0;j<n;j++) {
                // cout<<"a";
                string u = q.front();
                // cout<<u<<" ";
                for(auto x:v[s[i]-'0'-1]) {
                    q.push(u+x);
                    cout<<u+x<<" ";
                }
                q.pop();
            }
        }
        while(!q.empty()){ans.push_back(q.front()); q.pop();} 
        return ans;
    }
};