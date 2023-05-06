//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void func(vector<int>&a, int i, int n, vector<int>&ans, int sum) {
        if(i==n) {
            ans.push_back(sum);
            return;
        }
        func(a,i+1,n,ans,sum);
        func(a,i+1,n,ans,sum+a[i]);
        
    }
    vector<int> subsetSums(vector<int> a, int n)
    {
        vector<int>ans;
        func(a,0,n,ans,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends