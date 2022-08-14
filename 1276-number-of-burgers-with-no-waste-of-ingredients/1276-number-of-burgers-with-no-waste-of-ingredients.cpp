class Solution {
public:
    vector<int> numOfBurgers(int b, int a) {
        int ans1=0,ans2=0;
        vector<int>ans;
        // if(b<=a) return ans;
        while(b!=2*a && b>0 && a>0) {
            ans1++;
            b-=4;
            a-=1;
        }
        if(a*2==b) {
            ans2 = a;
        }
        else return ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};