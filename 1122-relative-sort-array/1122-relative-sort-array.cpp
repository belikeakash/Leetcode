class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a2, vector<int>& a1) {
        vector<int>ans;
        for(int i=0;i<a1.size();i++) {
            for(int j=0;j<a2.size();j++) {
                if(a1[i]==a2[j]) {ans.push_back(a2[j]); a2[j] = -1;}
            }
        }
        vector<int>ans2;
        
        for(int i=0;i<a2.size();i++) if(a2[i]!=-1) ans2.push_back(a2[i]);
        sort(ans2.begin(),ans2.end());
        for(auto x:ans2) {
            ans.push_back(x);
        }
        return ans;
    }
};