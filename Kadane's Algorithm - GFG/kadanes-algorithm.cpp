//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    #define ll long long
    //Function to find the sum of contiguous subarray with maximum sum.
    long long ans = INT_MIN;
    long long func(int i, int a[], int n) {
        if(i==n) return 0;
        long long ans1 = -10000000000009;
        long long ans2 = -10000000000009;
        
        ans1 = a[i] + func(i+1,a,n);
        ans2 = a[i];
        ans = max(ans,max(ans1,ans2));
        return   max(ans1,ans2);
    }
    long long maxSubarraySum(int a[], int n){
        
        // Your code here
        func(0,a,n);
        return ans;
        // ll sum = LONG_MIN;
        // ll best = LONG_MIN;
        // int x = 0;
        
        // for(int i=0;i<n;i++) {
        //     sum+=a[i];
        //     sum = max(1LL*a[i],sum);
        //     best = max(best,sum);
        // }
        // ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends