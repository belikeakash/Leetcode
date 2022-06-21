class Solution {
public:
    int kConcatenationMaxSum(vector<int>& a, int k) {
        int n = a.size();
        long long int s1=0,s2=a[0],s3=0;
        long long int p1=(long long int)a[0]*1L,p2=(long long int)a[0]*1L,p3=(long long int)a[n-1]*1L;
        for(int i=0;i<n;i++) {
            s1+=a[i];
            p1 = max(p1,s1);
        }
        for(int i=n-1;i>=0;i--) {
            s3+=a[i];
            p3 = max(p3,s3);
        }
        long long int p4 = s3;
        
        for(int i=1;i<n;i++) {
            s2 = max((long long int)a[i]*1L,(long long int)(a[i]+s2)*1L);
            p2 = max(p2,s2);
        }
        cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
        if(k==1) return max({p1,p2,p3,p4})%1000000007;
        int x = 0;
        if(p4>0) x+=((k-2)*p4)%1000000007;
        if(p1>0) x+=p1;
        if(p3>0) x+=p3;
        
        if(p2>x) return p2%1000000007;
        return x%1000000007;
            
        // return 0;
    }
};