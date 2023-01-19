//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i=0;i<n;i++) {if(a[i]==0) cnt0++; else if(a[i]==1) cnt1++;}
        int i = 0,j = cnt0, k = n-1, x=0;
        while(i<n) {
            if(i<cnt0) {
                if(a[i]==0) i++;
                else if(a[i]==2) {
                    swap(a[i],a[k]);
                    k--;
                }
                else if(a[i]==1) {
                    swap(a[i],a[j]);
                    j++;
                }
            }
            else if(i<cnt1+cnt0) {
                if(a[i]==1) i++;
                // else if(a[x]==0) {
                //     swap(a[x],a[i]);
                //     i++;
                // }
                else if(a[i]==2) {
                    swap(a[i],a[k]);
                    k--;
                }
            }
            else {
                // if(a[x]==2) x++;
                // else if(a[x]==0) {
                //     swap(a[x],a[i]);
                //     i++;
                // }
                // else if(a[x]==1) {
                //     swap(a[x],a[j]);
                //     j++;
                // }
                i++;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends