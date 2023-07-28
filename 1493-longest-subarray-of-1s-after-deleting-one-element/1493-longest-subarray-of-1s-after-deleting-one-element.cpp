class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        int i = 0, j=0;
        int ans = 0;
        int cnt = 0;
        // while(j<n) {
        //     if(a[j]==0) cnt++;
        //     if(cnt>1) {
        //         while(cnt>1 && i<j) {
        //             if(a[i]==0) cnt--;
        //             i++;
        //         }
        //     }
        //     ans = max(ans, j-i+1);
        //     j++;
        // }
        // return ans;
        vector<int>left(n,0);
        vector<int>right(n,0);
        int c = 0;
        bool flag = 0;
        for(int i=0;i<n;i++) {
            if(a[i]==1) c++;
            else{
                left[i] = c;
                c=0;
                flag=1;
            }
        }
        c=0;
        for(int i=n-1;i>=0;i--) {
            if(a[i]==1) {c++;}
            else{
                right[i] = c;
                c=0;
                 flag=1;
            }
        }
        for(int i=0;i<n;i++) {
            ans = max(ans, left[i]+right[i]);
        }
        
        if(!flag) return n-1;
        return ans;
    }
};