class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(auto q: queries){
            int i = 0;
            int j = 0;
            while(i < q.size()){
                if(q[i] >= 'A' && q[i] <= 'Z'){
                    if(j < pattern.size() && pattern[j] == q[i])
                        j++;
                    else
                        break;                        
                } else if(j < pattern.size() && pattern[j] == q[i])j++;
                i++;
            }
            if(i == q.size() && j == pattern.size()) res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};