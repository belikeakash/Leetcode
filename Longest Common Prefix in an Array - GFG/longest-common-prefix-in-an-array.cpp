//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string a[], int n)
    {
        string ans = "";
        int sz = 100008;
        for(int i = 0;i<n;i++) {
            int mp = a[i].size();
            sz = min(sz,mp);
        }
        bool flag = 0;
        for(int i = 0;i<sz;i++) {
            for(int j = 0;j<n-1;j++) {
                if(a[j][i]!=a[j+1][i]) {
                    flag = 1; break;
                }
            }
            if(flag) break;
            else {
                ans+=a[0][i];
            }
        }
        if(ans.size()>0) return ans;
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends