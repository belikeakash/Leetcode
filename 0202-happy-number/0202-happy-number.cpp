class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>m;
        while(m.count(n)==0) {
            m[n] = 1;
            int sum = 0;
            while(n>0) {
                int c = n%10;
                n = n/10;
                sum+=c*c;
            }
            if(sum==1) return 1;
            n = sum;
        }
        return 0;
    }
};