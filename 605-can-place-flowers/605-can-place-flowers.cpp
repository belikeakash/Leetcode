class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int x) {
        int n = a.size();
        // if(n==1){
        //   if(a[0]==1 && x==0) return 1;
        //     if(a[0]==1 && x>0) return 0;
        //     if(a[0]==0 && x==0) return 1;
        //     if(a[0]==0 && x==1) return 1;
        // }
        int i=0;
        int ans = 0;
        cout<<"a";
        while(i<n && a[i]!=1) i++;
        if(i==n) {
            return (i-1)/2 + 1>=x;
        }
        ans+=(i)/2;
        cout<<"a";
        // cout<<ans<<" ";
        int j = i+1;
        while(j<n) {
            
            if(a[j]==1) {
                ans+=(j-i-2)/2;
                cout<<ans<<" ";
                i = j;
            }
            j++;
        }
        if(a[n-1]==0 && j==n) {
            cout<<ans<<endl;
            ans+=(n-i-1)/2;
        }
        if(ans>=x) return 1;
        else return 0;
    }
};