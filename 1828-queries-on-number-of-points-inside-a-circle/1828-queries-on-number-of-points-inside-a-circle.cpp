class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<int>ans;
        for(int i=0;i<b.size();i++) {
            int cnt = 0;
            for(int j=0;j<a.size();j++) {
                if((b[i][0]-a[j][0])*(b[i][0]-a[j][0]) + (b[i][1]-a[j][1])*(b[i][1]-a[j][1]) <= b[i][2]*b[i][2]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};