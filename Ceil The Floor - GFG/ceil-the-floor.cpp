//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int a[], int n, int x) {
    int mini = 0;
    int maxi = 1000006;
    for(int i=0;i<n;i++) {
        if(a[i]<=x && a[i]>mini) {
            mini = a[i];
        }
        if(a[i]>=x && a[i]<maxi) {
            maxi = a[i];
        }
    }
    if(mini == 0) mini = -1;
    if(maxi == 1000006) maxi = -1;
    pair<int,int>ans={mini,maxi};
    return ans;
}