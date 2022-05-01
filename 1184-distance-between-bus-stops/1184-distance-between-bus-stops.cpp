class Solution {
public:
    int distanceBetweenBusStops(vector<int>& a, int s, int d) {
        if(s>=d) return distanceBetweenBusStops(a,d,s);
        int ans1 = 0,ans2=0;
        int n = a.size();
        for(int i=s;i<d;i++) ans1+=a[i];
        for(int i=d;i<n;i++) ans2+=a[i];
        for(int i=0;i<s;i++) ans2+=a[i];
        
        cout<<ans1<<" "<<ans2<<endl;
        return min(ans1,ans2);
    }
};