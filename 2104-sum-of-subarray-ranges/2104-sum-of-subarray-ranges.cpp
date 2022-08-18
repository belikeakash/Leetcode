class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
        int n = a.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i=0;i<n;i++) {
            left[i] = i;
            right[i] = n-i-1;
        }
        stack<int>s1;
        for(int i=0;i<n;i++) {
            while(!s1.empty() && a[s1.top()]>a[i]) {
                right[s1.top()] = i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        stack<int>s2;
        for(int i=n-1;i>=0;i--) {
            while(!s2.empty() && a[s2.top()]>=a[i]) {
                left[s2.top()] = s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        // int ans = 0;
        vector<int>p1(n,0);
        for(int i=0;i<n;i++) {
            p1[i] = (left[i]+1)*(right[i]+1);
        }
        vector<int>left2(n,0);
        vector<int>right2(n,0);
        for(int i=0;i<n;i++) {
            left2[i] = i;
            right2[i] = n-i-1;
        }
        stack<int>s3,s4;
        for(int i=0;i<n;i++) {
            while(!s3.empty() && a[i]>a[s3.top()]) {
                right2[s3.top()] = i - s3.top() - 1;
                s3.pop();
            }
            s3.push(i);
        }
        for(int i=n-1;i>=0;i--) {
            while(!s4.empty() && a[s4.top()]<=a[i]) {
                left2[s4.top()] = s4.top()-i-1;
                s4.pop();
            }
            s4.push(i);
        }
        vector<int>p2(n,0);
        for(int i=0;i<n;i++) {
            p2[i] = (left2[i]+1)*(right2[i]+1);
        }
        long long ans = 0;
        for(int i=0;i<n;i++) {
            cout<<p2[i]<<" "<<p1[i]<<"  ";
            ans+= (long long)(p2[i]-p1[i])*a[i];
        }
        cout<<endl;
        return ans;
        // int mini;
        // int maxi;
        // int mod = 1000000007;
        // long long ans = 0;
        // for(int i=0;i<n;i++) {
        //     mini = a[i];
        //     maxi = a[i];
        //     for(int j=i;j<n;j++) {
        //         mini = min(mini,a[j]);
        //         maxi = max(maxi,a[j]);
        //         ans+= (maxi - mini);
        //         // ans%=mod;
        //         // cout<<ans<<" ";
        //     }
        // }
        // return ans;
    }
};