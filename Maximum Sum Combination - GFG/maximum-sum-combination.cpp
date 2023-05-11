//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        priority_queue<pair<int, pair<int,int>>>pq;
        vector<int>ans;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        set<pair<int,int>>s;
        s.insert({0,0});
        pq.push({a[0]+b[0], {0,0}});
        for(int i=0;i<k;i++) {
            auto c = pq.top();
            pq.pop();
            ans.push_back(c.first);
            if(c.second.first+1<n && s.find({c.second.first+1,c.second.second})==s.end()) {
                pq.push({a[c.second.first+1]+b[c.second.second], {c.second.first+1,c.second.second}});
                s.insert({c.second.first+1,c.second.second});
            }
            if(c.second.second+1<n && s.find({c.second.first,c.second.second+1})==s.end()) {
                pq.push({a[c.second.first]+b[c.second.second+1], {c.second.first,c.second.second+1}});
                s.insert({c.second.first,c.second.second+1});
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends