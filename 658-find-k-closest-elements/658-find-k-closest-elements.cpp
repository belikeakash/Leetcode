class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        vector<int>ans;
        int n = a.size();
        int l = 0,r = n-1;
        int idx = -1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(a[mid]==x) {
                idx = mid;
                break;
            }
            else if(a[mid]>x) {
                r = mid-1;    
            }
            else {
                l = mid+1;
            }
        }
        int i,j;
        cout<<idx<<" ";
        if(idx!=-1) {
            cout<<"a";
        ans.push_back(a[idx]);
        if(k==1) return ans;
        k--;
        i = idx-1;
        j = idx+1;
        cout<<i<<" "<<j<<endl;
        while(k--) {
            if(i<0) {ans.push_back(a[j]); j++;}
            else if(j>n-1) {ans.push_back(a[i]); i--;}
            else if(abs(a[i]-a[idx])<=abs(a[j]-a[idx])) {
                ans.push_back(a[i]);
                i--;
            }
            else {
                ans.push_back(a[j]);
                j++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        }
        else {
            cout<<"B";
            i=-1;
            j = n;
            for(int u=0;u<n;u++) {
                if(a[u]<x) {
                    i = u   ;   
                }   
            }
            for(int u=n-1;u>=0;u--) {
                if(a[u]>x) {
                    j = u   ;   
                }   
            }
            cout<<i<<" "<<j<<endl;
        while(k--) {
            if(i<0) {ans.push_back(a[j]); j++;}
            else if(j>n-1) {ans.push_back(a[i]); i--;}
            else if(abs(a[i]-x)<=abs(a[j]-x)) {
                ans.push_back(a[i]);
                i--;
            }
            else {
                ans.push_back(a[j]);
                j++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        }
        
    }
};