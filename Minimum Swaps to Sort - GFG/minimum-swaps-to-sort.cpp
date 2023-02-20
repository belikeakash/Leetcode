//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    void DFS(int node, vector<vector<int>>&ar, vector<int>&vis, int& cnt) {
        vis[node] = 1;
        cnt++;
        for(auto x:ar[node]) {
            if(!vis[x]) {
                DFS(x,ar,vis,cnt);
            }
        }
    }
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&a)
	{
	    int n = a.size();
	    vector<pair<int,int>>b;
	    unordered_map<int,int>m;
	    for(int i=0;i<n;i++) {
	        b.push_back({a[i],i});
	    }
	    sort(b.begin(),b.end());
	    int res = 0;
	    vector<int>vis(n,0);
	    for(int i=0;i<n;i++) {
	        if(!vis[i] ) {
	            
	            int ans = 0;
	            int cc = b[i].second;
	            vis[cc]=1;
	            //cout<<cc<<" ";
	            while(cc!=i) {
	                ans++;
	                cc = b[cc].second;
	                //cout<<cc<<" ";
	                vis[cc] = 1;
	            }
	           // cout<<ans<<endl;
	            res+=ans;
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends