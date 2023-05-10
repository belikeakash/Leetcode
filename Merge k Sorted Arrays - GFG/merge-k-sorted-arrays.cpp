//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> merge(vector<int>&a, vector<int>&b) {
        vector<int>c;
        int n = a.size();
        int m = b.size();
        int i=0,j=0;
        while(i<n && j<m) {
            if(a[i]<b[j]) {
                c.push_back(a[i]);
                i++;
            }
            else {
                c.push_back(b[j]);
                j++;
            }
        }
        while(i<n) {
            c.push_back(a[i]);
            i++;
        }
        while(j<m) {
            c.push_back(b[j]);
            j++;
        }
        
        return c;
    }
    vector<int> mergeKArrays(vector<vector<int>> a, int K)
    {
        vector<int>v;
        v = a[0];
        int n = a.size();
        for(int i=1;i<n;i++) {
            v = merge(v,a[i]);
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends