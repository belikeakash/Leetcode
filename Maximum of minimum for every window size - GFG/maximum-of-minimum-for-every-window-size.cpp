//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int a[], int n)
    {
        stack<int>s;
        //vector<int>ans(n);
        vector<int>right(n);
        for(int i=0;i<n;i++) {
            right[i] = n-i;
        }
        for(int i=0;i<n;i++) {
            while(!s.empty() && a[i]<a[s.top()]) {
                right[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        vector<int>left(n);
        for(int i=0;i<n;i++) {
            left[i] = i+1;
        }
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() && a[i]<a[s.top()]) {
                left[s.top()] = s.top()-i;
                s.pop();
            }
            s.push(i);
        }
        //for(auto x:right) cout<<x<<" ";
        //cout<<endl;
        //for(auto x:left) cout<<x<<" ";
        //cout<<endl;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++) {
            v.push_back({a[i],left[i]+right[i] - 1}) ;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int u = 0;
        vector<int>ans(n);
        //for(auto x:v) cout<<x.second<<" ";
        for(int i=0;i<n;i++) {
            if(v[i].second>u) {
                //cout<<v[i].first<<" ";
                for(int p=u;p<v[i].second;p++) {
                ans[p] = v[i].first;
                u = v[i].second;
            }
            }
        }
        //cout<<endl;
        
        // cout<<endl;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends