class Solution {
public:
    int ans = 0;
    void func(int i, vector<int>&a) {
        
        if(i==a.size()) {
            ans++;    
            return;
        }
        for(int j=i;j<a.size();j++) {
            if(a[j]%(i+1)==0 || (i+1)%a[j]==0) {
                swap(a[i],a[j]);
                func(i+1,a);
                swap(a[i],a[j]);
            }
            
        }
    }
    int countArrangement(int n) {
        vector<int>a(n,0);
        for(int i=0;i<n;i++) a[i]=i+1;
        func(0,a);
        return ans;
    }
};