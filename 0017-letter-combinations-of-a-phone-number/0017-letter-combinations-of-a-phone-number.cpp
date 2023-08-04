class Solution {
public:
    vector<string> letterCombinations(string x) {
        unordered_map<char, vector<string>>m;
        m['2'] = {"a", "b", "c"};
        m['3'] = {"d", "e", "f"};
        m['4'] = {"g", "h", "i"};
        m['5'] = {"j", "k", "l"};
        m['6'] = {"m", "n", "o"};
        m['7'] = {"p", "q", "r", "s"};
        m['8'] = {"t", "u", "v"};
        m['9'] = {"w", "x", "y", "z"};
        deque<string>q;
        q.push_back("");
        int s = 0;
        for(int i=0;i<x.size();i++) {
            int n = q.size();
            cout<<x[i]<<endl;
            for(int j=0;j<n;j++) {
                string c = q.front();
                //cout<<c<<endl;
                q.pop_front();
                for(auto y:m[x[i]]) {
                    cout<<c+y<<" ";
                    q.push_back(c+y);
                }
            }
//             cout<<endl;
//             cout<<endl;
        }
        vector<string>ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        if(ans[0]=="") ans.pop_back(); 
        return ans;
    }
};