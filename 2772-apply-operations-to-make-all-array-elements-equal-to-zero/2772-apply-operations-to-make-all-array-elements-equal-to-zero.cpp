class Solution {
public:
    bool checkArray(vector<int>& a, int k) {
        int n = a.size();
        if(a[0]<a[n-1]) reverse(a.begin(), a.end());
        int idx=0;
        while(idx<n && a[idx]==0) idx++;
        if(idx==n) return 1;
        for(int j=idx;j<n;j++) {
            //cout<<idx<<"->"<<n<<"  ";
            if(idx+k>n) break;
            int mini = INT_MAX;
            for(int i=idx;i<idx+k;i++) {
                if(a[i]==0) return 0;
                mini = min(mini, a[i]);
            }
            bool flag = 0;
            //cout<<idx+k-1<<" "<<idx;
            for(int i=idx+k-1;i>=idx;i--) {
                //cout<<i<<" ";
                a[i]=a[i]-mini;
                
                 if(a[i]>0) { flag=i;}
            }
            //cout<<endl;
            if(flag==-1) idx = idx+k;
            else idx = flag;
            while(idx<n && a[idx]==0) idx++;
        }
        for(int i=0;i<n;i++) {
            // cout<<a[i]<<" ";
            if(a[i]!=0) return 0;
        }
        return 1;
    }
};