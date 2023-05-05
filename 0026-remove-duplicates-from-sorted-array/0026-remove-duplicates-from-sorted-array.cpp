class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int i = 0;
        int p = 0;
        while(i<n-p) {
            int j = i+1;
            while(j<n-p && a[j]==a[i]) {
                j++;
            }
            //cout<<j<<" ";
            if(j!=i+1 && j<n) {
                int u = j-i-1;
                p+=u;
                for(int x=i+1;x<n-u;x++) {
                    a[x]=a[x+u];
                }
                i = i+1;;
            }
            else {
                i=i+1;
            }
            
        }
        // cout<<p<<" ";
        // cout<<endl;
        i = 0;
        int cnt = 1;
        // for(int x=0;x<n;x++) {
        //     cout<<a[x]<<" ";
        // }
        // cout<<endl;
        while(i<n-1-p && a[i]!=a[i+1]) {
            cnt++;
            i++;
        }
        
        return cnt;
    }
};