class Solution {
public:
    bool judgeSquareSum(int c) {
        int i =0;
        int j = sqrt(c);
        while(i<=j) {
            if((long long)i*i + (long long)j*j == (long long)c) return 1;
            else if((long long)i*i + (long long)j*j > (long long)c) j--;
            else i++;
        }
        return 0;
    }
};