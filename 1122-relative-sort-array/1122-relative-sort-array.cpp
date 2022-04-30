class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a1, vector<int>& a2) {
        map<int,int>m;
        for(auto x:a1) m[x]++;
        int i = 0;
        for(auto x:a2) {
            while(m[x]>0) {
                a1[i]=x;
                i++;
                m[x]--;
            }
        }
        for(auto x:m) {
            while(x.second-- >0) a1[i++]=x.first;
        }
        return a1;
    }
};