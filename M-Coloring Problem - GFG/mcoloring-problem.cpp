//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isValid(int p, int node, vector<vector<int>>&ar, vector<int>&c) {
        for(auto x:ar[node]) {
                if(c[x]==p) return 0;
        }
        return 1;
    }
    int func(int node, vector<vector<int>>&ar, vector<int>&v, vector<int>&c, int n) {
        if(node==ar.size()) return 1;
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(isValid(i,node,ar,c)) {
                //cout<<node<<" "<<i<<endl;
                c[node] = i;
                int u = func(node+1,ar,v,c,n);
                ans = ans || u;
                if(u) return 1;
                c[node] = 0;
            }
        }
        return ans;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>>ar(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(graph[i][j]==1) {
                    ar[i].push_back(j);
                }
            }
        }
        vector<int>v(n,0),c(n,0);
        int ans = 1;
        
        if(func(0, ar, v, c, m)) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends