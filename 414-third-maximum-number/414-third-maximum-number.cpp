class Solution {
public:
    int thirdMax(vector<int>& a) {
        long long m1=LONG_MIN,m2=LONG_MIN,m3=LONG_MIN;
        for(auto x:a) {
            if(x==m1 || x==m2 || x==m3) continue;
            if(x>m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            }
            else if(x>m2) {
                m3 = m2;
                m2 = x;
            }
            else if(x>m3) {
                m3 = x;
            }
        }
        if(m3==LONG_MIN) return m1;
        return m3;
    }
};