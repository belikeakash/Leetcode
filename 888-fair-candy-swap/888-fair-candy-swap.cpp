class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int s1=0,s2=0;
        unordered_map<int,int>m;
        for(auto x:a) s1+=x;
        for(auto x:b) {s2+=x; m[2*x]++;}
        int d = s1-s2;
        vector<int>ans;
        for(auto x:a) {
            if(m[2*x - d]>0) {
                ans.push_back(x);
                ans.push_back((2*x - d)/2);
                break;
            }
        }
        return ans;
    }
};