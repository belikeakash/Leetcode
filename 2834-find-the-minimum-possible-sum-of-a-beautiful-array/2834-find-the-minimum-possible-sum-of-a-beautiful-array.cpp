class Solution {
public:
    long long minimumPossibleSum(int n, int x) {
        int cnt = n;
        long long ans = 0;
        unordered_map<int, int>m;
        for(int i=1;i<=n;i++) {
            if(m[x-i]) {
                cout<<i<<" "<<x-i<<endl;
                cnt--;
            }
            else {
                ans=ans+i;
            }
            m[i]=1;
        }
        int i = n+1;
        while(cnt<n) {
            if(m[x-i]) {
                i++;
                continue;
            }
            else {
                ans=ans+i;
                cnt++;
                m[i]=1;
            }
            i++;
            
        }
        
        return ans;
    }
};