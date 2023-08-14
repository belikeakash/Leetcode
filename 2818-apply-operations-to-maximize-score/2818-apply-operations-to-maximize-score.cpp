class Solution {
public:
    int N = 100005;
    int spf[100006];
    int mod = 1e9+7;
    void seive() {
        for(int i=0;i<=N;i++) spf[i] = i;
        for(int i=2;i*i<=N;i++) {
            if(spf[i]==i) {
                for(int j=i*i;j<=N;j+=i) {
                    if(spf[j]==j) spf[j] = i;
                }
            }
        }
    }
    int power(long long x, unsigned int y, int p = 1e9+7)
    {
        int res = 1;     // Initialize result

        x = x % p; // Update x if it is more than or
                    // equal to p

        if (x == 0) return 0; // In case x is divisible by p;

        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;

            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    } 
    int maximumScore(vector<int>& a, int k) {
        seive();
        int n = a.size();
        vector<pair<int, long long>>v;
        for(int i=0;i<n;i++) {
            int c = a[i];
            if(c==1) {
                v.push_back({1,0});
                continue;
            }
            set<int>s;
            while(c!=1) {
                s.insert(spf[c]);
                c=c/spf[c];
            }
            v.push_back({a[i], s.size()});
        }
        
        // for(auto x:v) {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        long long ans = 1;
        vector<int>left(n,0);
        stack<int>st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && (v[i].second>v[st.top()].second)) {
                left[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            //cout<<st.top()<<" ";
            left[st.top()] = n - st.top();
            st.pop();
        }
        
        // for(auto x:left) cout<<x<<" ";
        // cout<<endl;
        vector<int>right(n,0);
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && (v[i].second>=v[st.top()].second)) {
                right[st.top()] = st.top() - i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            //cout<<st.top()<<" ";
            right[st.top()] = st.top()+1;
            st.pop();
        }
        // for(auto x:right) cout<<x<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++) {
            v[i].second = (1LL*left[i])*(1LL*right[i]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int i = 0;
        while(k) {
            // cout<<"A";
            long long t = min(v[i].second, 1LL*k);
            ans = (1LL*ans*power(v[i].first, t))%mod;
            k=k-t;
            i++;
        }
        return ans;
        //return ans;
    }
};