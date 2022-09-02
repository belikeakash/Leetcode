class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>>s;
        s.push(1);
        long long x = 1;
        if(n==1) return 1;
        for(int i=0;i<n;i++) {
            x = s.top();
            while(!s.empty() && s.top()==x) {
                s.pop();
            }
            s.push(x*2);
            s.push(x*3);
            s.push(x*5);
        }
       
        return x;
    }
};