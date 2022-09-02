class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        int i=0,j=0;
        multiset<int>s;
        vector<double>ans;
        while(j<k) {
            s.insert(a[j]);
            j++;
        }
        if(k%2==0) {
            int u = 1;
            long long sum = 0;
            for(auto x:s) {
                if(u==k/2 || u==k/2 + 1) sum+=x;
                u++;
            }
            cout<<sum<<" ";
            ans.push_back((double)sum/(double)2);
        }
        else {
            int u = 1;
            long long sum = 0;
            for(auto x:s){
                if(u==k/2 + 1) sum+=x;
                u++;
            }
            cout<<sum<<" ";
            ans.push_back(sum);
        }
        while(j<n) {
            s.insert(a[j]);
            s.erase(s.find(a[i]));
            i++;
            if(k%2==0) {
                int u = 1;
                 long long sum = 0;
                for(auto x:s) {
                    if(u==k/2 || u==k/2 + 1) sum+=x;
                    u++;
                }
            ans.push_back((double)sum/(double)2);
            }
            else {
                int u = 1;
                long long sum = 0;
                for(auto x:s){
                    if(u==k/2 + 1) sum+=x;
                    u++;
                }
                ans.push_back(sum);
            }
            j++;
        }
        return ans;
    }
};