class Solution {
public:
    vector<int> intersect(vector<int>& a1, vector<int>& a2) {
        int n1 = a1.size();
        int n2 = a2.size();
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        int i1=0,i2=0;
        vector<int>ans;
        while(i1<n1 && i2<n2) {
            if(a1[i1]==a2[i2]) {
                ans.push_back(a1[i1]);
                i1++;
                i2++;
            }
            else if(a1[i1]<a2[i2]) {
                i1++;
            }
            else i2++;
        }
        return ans;
    }
};