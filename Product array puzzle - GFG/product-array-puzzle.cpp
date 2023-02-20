//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
       
        long long mul = 1;
        int cnt = 0;
        vector<long long int>ans;
        for(int i=0;i<n;i++) {
            if(a[i]==0) {cnt++; continue;}
            mul = mul*a[i];
        }
        for(int i=0;i<n;i++) {
            if(cnt>1) {
                ans.push_back(0);
            }
            else if(cnt==1) {
                if(a[i]==0) {
                    ans.push_back(mul);
                }
                else {
                    ans.push_back(0);
                }
            }
            else {
                ans.push_back(mul/a[i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends