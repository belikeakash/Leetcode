class Solution {
public:
    int arrayPairSum(vector<int>& a) {
        vector<int>v(20004,0);
        for(auto x:a) {
            v[x+10000]++;
        }
        int sum = 0;
        int flag = 1;
        int i=0;
        for(auto x:v) {
            while(x>0) {
                if(flag) {
                    sum += i-10000;
                }
                flag = !flag;
                x--;
            }
            i++;
        }
        return sum;
    }
};