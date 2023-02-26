class Solution {
public:
    int missingNumber(vector<int>& a) {
        int sz = a.size();
        int i = 0;
        while(i<sz) {
            if(i==a[i]) i++;
            else if(a[i]>=sz) i++;
            else swap(a[i],a[a[i]]);
        }
        for(int i=0;i<sz;i++) {
            if(a[i]!=i) return i;
        }
        return sz;
    }
};