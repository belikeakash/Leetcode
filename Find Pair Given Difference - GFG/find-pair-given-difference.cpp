//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int a[], int size, int n){
    sort(a,a+size);
    unordered_map<int,int>m;
    for(int i=0;i<size;i++) {
        if(m[a[i]-n]) return 1;
        m[a[i]] = 1;
    }
    return 0;
}