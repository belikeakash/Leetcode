class Solution {
public:
    int divide(int a, int b) {
        if(a==INT_MIN && b==-1) return INT_MAX;
        if(a==INT_MIN && b==1) return INT_MIN;
        int x = a/b;
        return x;
    }
};