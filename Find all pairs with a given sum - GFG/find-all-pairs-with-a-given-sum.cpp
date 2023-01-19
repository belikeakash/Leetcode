//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b) {
        return a.first<b.first;
    }
    vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int X)
    {
        // Your code goes here   
        sort(a,a+n);
        sort(b,b+m);
        vector<pair<int,int>>ans;
        for(int i = 0;i<n;i++) {
            int l = 0,r = m-1;
            while(l<=r) {
                int mid = l+(r-l)/2;
                if(b[mid]+a[i]==X) {
                    pair<int,int>p = {a[i],b[mid]};
                    l = mid + 1;
                    ans.push_back(p);
                }
                else if(b[mid]+a[i]>X) r = mid -1 ;
                else l = mid + 1;
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends