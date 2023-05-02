class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int x) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(int i=0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++) {
                int l = j+1,r=n-1;
                while(l<r) {
                    long long sum = 1LL*a[i]+ 1LL*a[j]+ 1LL*a[l]+ 1LL*a[r];
                    if(sum==1LL*x) {
                        s.insert({a[i],a[j],a[l],a[r]});
                        //cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
                        l++;
                        r--;
                    }
                    else if(sum<1LL*x) {
                        l++;
                    }
                    else {r--;}
                }
            }
        }
        for(auto x:s) {
            ans.push_back(x);
        }
        return ans;
    }
};