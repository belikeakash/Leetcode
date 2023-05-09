//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int func(int c, vector<vector<int>>&a) {
        int x = 0;
        int y = 0;
        int u = 0;
        int v = 0;
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<n;i++) {
            int l = 0,r=m-1;
            int p = 0;
            while(l<=r) {
                int mid = l+(r-l)/2;
                if(a[i][mid]<=c) {
                    p = mid;
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
            u+=l;
        }
        return u;
    }
    int median(vector<vector<int>> &a, int m, int n){
        int l = 1;
        int r = 100000;
        // for(int i=0;i<n;i++) {
        //     l = min(l,a[i][0]);
        //     r = max(r,a[i][m-1]);
        // }
        while(l<=r) {
            
            int mid = l+(r-l)/2;
            int cnt = func(mid,a);
            //if(cnt==(n*m)/2) return mid;
            if(cnt>(n*m)/2) {
                r = mid-1;
            }
            else l = mid+1;
        }
        
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends