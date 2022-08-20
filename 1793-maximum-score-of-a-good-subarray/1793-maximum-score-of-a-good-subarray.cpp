class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        vector<int>p1,p2;
        int n = a.size();
        int mini = a[k];
        for(int i=k;i<n;i++) {
            mini = min(mini,a[i]);
            p2.push_back(mini);
        }
        mini = a[k];
        for(int i=k;i>=0;i--) {
            mini = min(mini,a[i]);
            p1.push_back(mini);
        }
        
        reverse(p1.begin(),p1.end());
        for(int i=0;i<p1.size();i++) a[i]=p1[i];
        for(int i=0;i<p2.size();i++) a[i+k] = p2[i];
        int ans = 0;
        // for(auto x:a) cout<<x<<" ";
        // cout<<endl;
        int i = 0;
        int j = n-1;
        while(i<=j) {
            int x = min(a[i],a[j])*(j-i+1);
            ans = max(ans,x);
            if(a[i]>a[j]) j--;
            else i++;
        }
        return ans;
    }
};