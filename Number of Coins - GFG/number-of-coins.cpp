//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int ans = 0;
	public:
	vector<int>dp;
	int func(int sum,int n, int a[]) {
	    if(sum==0) return 0;
	    if(dp[sum]!=-1)return dp[sum];
	    int cnt = INT_MAX;
	    
	    for(int i=0;i<n;i++) {
	        if(sum-a[i]>=0) {
	            int xcnt =  func(sum-a[i],n,a);
	            if(xcnt!=INT_MAX ) {
	                cnt = min(cnt,1 + xcnt) ;
	            }
	        }
	    }
	    return dp[sum] = cnt;
	}
	int minCoins(int coins[], int m, int V) 
	{ 
	    // Your code goes here
	    dp.resize(1000006,-1);
	    return func(V,m,coins)==INT_MAX?-1 : func(V,m,coins);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends