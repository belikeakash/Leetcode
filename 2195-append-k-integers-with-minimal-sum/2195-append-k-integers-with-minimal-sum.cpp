class Solution {
public:
    long long minimalKSum(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        long long int ans = (long long int)k*(long long int)((k+1))/(long long int)2;
        vector<int>v;
        v.push_back(a[0]);
        for(int i=1;i<a.size();i++) {
            if(a[i]!=a[i-1]) v.push_back(a[i]); 
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++) {
            if(v[i]<=k) {
                k++;
                cout<<ans<<" ";
                ans=ans-v[i]+k;
                
            }
            else {
                break;
            }
        }
        return ans;
    }
};