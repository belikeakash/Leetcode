class Solution {
public:
    int canCompleteCircuit(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int s1=0,s2=0;
        for(auto x:a) s1+=x;
        for(auto x:b) s2+=x;
        if(s1<s2) return -1;
        int x = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            x+=a[i]-b[i];
            if(x<0) {ans = i+1; x = 0;}
        }
        return ans;
    }
};