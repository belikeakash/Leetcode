class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size();
        int prev = a[0];
        int ans = 0;
        bool flag = 1;
        for(int i=1;i<n;i++) {
            cout<<ans<<" ";
            if(flag==1) {
                
                if(a[i]-prev<=0) ans++;
                else {flag = 0;}
                prev = a[i];
            }
            else if(flag==0) {
                // flag = 1;
                if(a[i]-prev>=0) ans++;
                else {flag = 1;}
                prev = a[i];
            }
        }
        
        int p1 = n-ans;
        cout<<ans<<" ";
        prev = a[0];
        flag = 0;
        ans = 0;
        for(int i=1;i<n;i++) {
            if(flag==1) {
                
                if(a[i]-prev<=0) ans++;
                else { flag = 0;}
                prev = a[i];
            }
            else if(flag==0) {
                // flag = 1;
                if(a[i]-prev>=0) ans++;
                else { flag = 1;}
                prev = a[i];
            }
        }
        int p2 = n-ans;
        cout<<p2<<endl;
        cout<<endl;
        // cout<<p1<<" "<<p2<<endl;
        return max(p1,p2);
    }
};