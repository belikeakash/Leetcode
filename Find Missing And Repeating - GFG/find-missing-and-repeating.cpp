//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) {
        int*ans = new int[2];
        
        for(int i=0;i<n;i++) {
            //cout<<a[i]<<" ";
            if(a[abs(a[i])-1]<0) {
                ans[0] = abs(a[i]);
            }
            else a[abs(a[i])-1] = -a[abs(a[i])-1];
        }
        //cout<<endl;
        for(int i=0;i<n;i++) {
            if(a[i]>0) {
                ans[1] = i+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends