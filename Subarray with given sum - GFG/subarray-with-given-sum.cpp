//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>a, int n, long long s)
    {
        int l = 0, r = 0;
        long long sum = a[0];
        if(sum==s) {
            vector<int>ans = {1,1};
            return ans;
        }
        r = 0;
        while(r<n) {
            r++;
            sum+=a[r];
            while(sum>s && l<r) {
                sum-=a[l];
                l++;
            }
            //cout<<sum<<endl;
            if(sum==s) {
                vector<int>ans = {l+1,r+1};
                if(l>=n || r>=n) continue;
                return ans;
            }
        }
        vector<int>ans = {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends