class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        vector<int>v(10004,0);
        int n = a.size();
        for(auto x:a) v[abs(x)]++;
        vector<int>ans;
        for(int i=0;i<10004;i++) {
            if(v[i]>0) {
                while(v[i]-->0) ans.push_back(i*i);
            }
        }
        return ans;
    }
};