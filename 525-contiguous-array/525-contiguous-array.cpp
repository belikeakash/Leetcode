class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int,int>m;
        m[0]=-1;
        for(int i=0;i<n;i++) {
            if(a[i]==1) sum+=1;
            else sum-=1;
            if(m.count(sum)) {
                ans = max(ans,i-m[sum]);
            }
            else {
                m[sum] = i;
            }
        }
        
        
        
        cout<<endl;
        return ans;
    }
};