class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        if(n<2) return 0;
        if(k==0) return 1;
        map<int,int>m;
        m[0]=-1;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum = sum + a[i];
            
            cout<<sum<<" ";
            if(m.find(sum%k)!=m.end()) {
                if(i-m[sum%k]>1) return 1;
            }
            else m[sum%k]=i;
            
        }
        return 0;
    }
};