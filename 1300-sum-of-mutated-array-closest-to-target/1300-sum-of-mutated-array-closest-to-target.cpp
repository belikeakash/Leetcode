class Solution {
public:
    int findBestValue(vector<int>& a, int t) {
        int n = a.size();
        sort(a.begin(),a.end());
        int l = 0 ,r = a[n-1],s=-1;
        int mid = 100000000;
        while(l<=r) {
            mid = l+(r-l)/2;
            int ans = 0;
            for(int i=0;i<n;i++) {
                if(a[i]>mid) ans+=mid;
                else ans+=a[i];
            }
            if(ans<t) {
                l = mid+1;
            }
            else {
                r = mid - 1;
            }
        }
        int p = 0;
        for(int i=0;i<n;i++) {
                if(a[i]>mid) p+=mid;
                else p+=a[i];
        }
        int p2 = 0,p3=0;
        for(int i=0;i<n;i++) {
                if(a[i]>mid-1) p2+=mid-1;
                else p2+=a[i];
        }
        for(int i=0;i<n;i++) {
                if(a[i]>mid+1) p3+=mid+1;
                else p3+=a[i];
        }
        
        cout<<mid<<" ";
        cout<<p<<" "<<p2<<" "<<p3<<endl;
        if(abs(p-t)>=abs(p2-t) && abs(p2-t)<=abs(p3-t)) return mid-1;
        else if(abs(p-t)<=abs(p3-t)) return mid;
        return mid+1;
    }
};