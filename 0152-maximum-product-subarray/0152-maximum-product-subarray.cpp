class Solution {
public:
    int ans = INT_MIN;
    vector<long long>dp;
    
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int i = 0;
        int ans = INT_MIN;
        while(i<n) {
            // cout<<"a";
            int j = i;
            int neg = 0;
            while(j<n && a[j]!=0) {
                if(a[j]<0) neg++;
                j++;
            }
            int l = i, r = j-1;
            int mini = a[l];
            if(neg%2==0) {
                for(int k=l+1;k<=r;k++) mini = mini*a[k];
                ans=max(ans, mini);
            }
            else {
                int prod = 1;
                int mini = INT_MIN;
                for(int k=l;k<=r;k++) {
                    prod=prod*a[k];
                }
                int m1 = a[l], m2 = INT_MIN;
                if(a[l]<0) {
                    if(l<r) m2 = prod/(m1);
                    mini = max({mini, m1, m2});
                }
                for(int k=l+1;k<=r;k++) {
                    if(a[k]<0) {
                        if(l<r) m2 = prod/(m1*a[k]);
                        mini = max({mini, m1, m2});
                    }
                    m1 = m1*a[k];
                    
                }
                mini= max(mini, m1);
                ans = max(ans, mini);
            }
            if(j<n && a[j]==0)ans = max(ans, 0);
            i = j+1;
        }
        
        return ans;
    }
};