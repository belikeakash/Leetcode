class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& a) {
        int sum = 0;
        for(auto x:a) sum+=x;
        if(sum%3!=0) return 0;
        int x = sum/3;
        int y = 0;
        int n = a.size();
        int cnt = 0,i;
        for(i=0;i<n;i++) {
            y+=a[i];
            if(y==x) {cnt++; y=0; if(cnt==3)break;}
        }
        
        // if(cnt==2 && sum-2*x==x && i<n-1) return 1;
        if(cnt==3) return 1;
        return 0;
    }
};