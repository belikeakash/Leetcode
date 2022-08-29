class Solution {
public:
    int func(vector<int>&a, int x) {
        int ans = 0,n=a.size();
        int i=0,j=1;
        while(i<n) {
            while(j<n && a[j]-a[i]<=x) {
                j++;
            }
            ans+=j-i-1;
            i++;
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n = a.size();
        int l = 0; 
        int r = a[n-1]-a[0];
        int ans = -1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            int x = func(a,mid);
            if(x>=k) {
                ans=mid;
                r=mid-1;
            }
            else {
                l = mid+1;
            }
        }
    return ans;
        
//         for(int i=ans;i<=r;i++) {
//             for(int j=i+1;j<r;j++) {
//                 int d = a[j]-a[i];
//                 q.push(d);
//             }
//         }
        
    }
};