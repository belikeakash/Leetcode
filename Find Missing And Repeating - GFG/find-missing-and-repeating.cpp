//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {
        vector<int>ans;
    int sum = 0;
    for(auto x:a) {
        sum+=x;
    }
    int i = 0;
    int n1 = -1;
    // cout<<"a";
    while(i<n) {
        //cout<<i<<"->";
        while(a[i]!=i+1) {
            if(a[a[i]-1]==a[i]) {
                n1 = a[i];
                break;
            }
            else {
                swap(a[i], a[a[i]-1]);
            }
        }
        // if(n1!=-1) break;
        i++;
    }

    for(int i=0;i<n;i++) {
        if(a[i]!=i+1) {
            ans.push_back(a[i]);
            ans.push_back(i+1);
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
        vector<int> a(n);
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